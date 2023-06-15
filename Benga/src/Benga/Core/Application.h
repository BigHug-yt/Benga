#pragma once

#include "Benga/Core/Base.h"

#include "Benga/Core/Window.h"
#include "Benga/Core/LayerStack.h"
#include "Benga/Events/Event.h"
#include "Benga/Events/ApplicationEvent.h"
#include "Benga/Events/KeyEvent.h"
#include "Benga/Events/MouseEvent.h"

#include "Benga/Core/Timestep.h"

#include "Benga/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Benga {

	struct ApplicationCommandLineArgs {

		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const {

			BG_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	struct ApplicationSpec {

		std::string Name = "Benga application";
		std::string WorkingDirectory;
		ApplicationCommandLineArgs CommandLineArgs;
	};

	class Application {

	public:
		Application(const ApplicationSpec& spec);
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }

		const ApplicationSpec& GetSpec() const { return m_Spec; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		ApplicationSpec m_Spec;
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in client
	Application* CreateApplication(ApplicationCommandLineArgs args);
}
