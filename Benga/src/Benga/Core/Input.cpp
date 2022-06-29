#include "bgpch.h"
#include "Benga/Core/Input.h"

#ifdef BG_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace Benga {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create() {

	#ifdef BG_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
	#else
		BG_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}
}