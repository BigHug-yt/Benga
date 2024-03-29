#pragma once
#include "Benga/Core/Base.h"

#ifdef BG_PLATFORM_WINDOWS

extern Benga::Application* Benga::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv) {
	
	Benga::Log::Init();

	BG_PROFILE_BEGIN_SESSION("Startup", "BengaProfile-Startup.json");
	auto app = Benga::CreateApplication({ argc, argv });
	BG_PROFILE_END_SESSION();

	BG_PROFILE_BEGIN_SESSION("Runtime", "BengaProfile-Runtime.json");
	app->Run();
	BG_PROFILE_END_SESSION();

	BG_PROFILE_BEGIN_SESSION("Shutdown", "BengaProfile-Shutdown.json");
	delete app;
	BG_PROFILE_END_SESSION();
}

#endif
