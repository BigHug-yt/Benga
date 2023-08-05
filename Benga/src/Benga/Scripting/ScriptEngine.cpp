#include "bgpch.h"
#include "Benga/Scripting/ScriptEngine.h"

#include "mono/jit/jit.h"
#include "mono/metadata/assembly.h"

namespace Benga {

	struct ScriptEngineData {

		MonoDomain* RootDomain = nullptr;
		MonoDomain* AppDomain = nullptr;

		MonoAssembly* CoreAssembly = nullptr;
	};

	static ScriptEngineData* s_Data = nullptr;

	char* ReadBytes(const std::string& filepath, uint32_t* outSize) {

		std::ifstream stream(filepath, std::ios::binary | std::ios::ate);

		if (!stream) {
			return nullptr;
		}

		std::streampos end = stream.tellg();
		stream.seekg(0, std::ios::beg);
		uint32_t size = end - stream.tellg();

		if (size == 0) {
			return nullptr;
		}

		char* buffer = new char[size];
		stream.read((char*)buffer, size);
		stream.close();

		*outSize = size;
		return buffer;
	}

	MonoAssembly* LoadCSharpAssembly(const std::string& assemblyPath) {

		uint32_t fileSize;
		char* fileData = ReadBytes(assemblyPath, &fileSize);

		MonoImageOpenStatus status;
		MonoImage* image = mono_image_open_from_data_full(fileData, fileSize, 1, &status, 0);

		if (status != MONO_IMAGE_OK) {
			const char* errorMessage = mono_image_strerror(status);

			return nullptr;
		}

		MonoAssembly* assembly = mono_assembly_load_from_full(image, assemblyPath.c_str(), &status, 0);
		mono_image_close(image);

		delete[] fileData;

		return assembly;
	}

	void PrintAssemblyTypes(MonoAssembly* assembly) {

		MonoImage* image = mono_assembly_get_image(assembly);
		const MonoTableInfo* typeDefinitionsTable = mono_image_get_table_info(image, MONO_TABLE_TYPEDEF);
		int32_t numTypes = mono_table_info_get_rows(typeDefinitionsTable);

		for (int32_t i = 0; i < numTypes; i++) {

			uint32_t cols[MONO_TYPEDEF_SIZE];
			mono_metadata_decode_row(typeDefinitionsTable, i, cols, MONO_TYPEDEF_SIZE);

			const char* nameSpace = mono_metadata_string_heap(image, cols[MONO_TYPEDEF_NAMESPACE]);
			const char* name = mono_metadata_string_heap(image, cols[MONO_TYPEDEF_NAME]);

			BG_CORE_INFO("{0}.{1}", nameSpace, name);
		}
	}

	void ScriptEngine::Init() {

		s_Data = new ScriptEngineData();

		InitMono();
	}

	void ScriptEngine::Shutdown() {

		ShutdownMono();

		delete s_Data;
	}

	void ScriptEngine::InitMono() {

		mono_set_assemblies_path("mono/lib");

		MonoDomain* rootDomain = mono_jit_init("BengaJITRuntime");
		BG_CORE_ASSERT(rootDomain);
		s_Data->RootDomain = rootDomain;

		s_Data->AppDomain = mono_domain_create_appdomain("BengaScriptRuntime", nullptr);
		mono_domain_set(s_Data->AppDomain, true);

		s_Data->CoreAssembly = LoadCSharpAssembly("Resources/Scripts/Benga-ScriptCore.dll");
		PrintAssemblyTypes(s_Data->CoreAssembly);

		MonoImage* assemblyImage = mono_assembly_get_image(s_Data->CoreAssembly);
		MonoClass* monoClass = mono_class_from_name(assemblyImage, "Benga", "Main");
		MonoObject* instance = mono_object_new(s_Data->AppDomain, monoClass);
		mono_runtime_object_init(instance);

		MonoMethod* printMessageFunc = mono_class_get_method_from_name(monoClass, "PrintMessage", 0);
		mono_runtime_invoke(printMessageFunc, instance, nullptr, nullptr);

		MonoMethod* printCustomMessageFunc = mono_class_get_method_from_name(monoClass, "PrintCustomMessage", 1);
		
		MonoString* monoString = mono_string_new(s_Data->AppDomain, "Hello world from C++");
		void* params[1] = {
			monoString
		};
		mono_runtime_invoke(printCustomMessageFunc, instance, params, nullptr);

		
	}

	void ScriptEngine::ShutdownMono() {

		// mono_domain_unload(s_Data->AppDomain);
		s_Data->AppDomain = nullptr;

		// mono_jit_cleanup(s_Data->RootDomain);
		s_Data->RootDomain = nullptr;
	}
}