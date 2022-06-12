#pragma once

#ifdef BG_PLATFORM_WINDOWS

extern Benga::Application* Benga::CreateApplication();

int main(int argc, char** argv) {
	
	Benga::Log::Init();
	BG_CORE_WARN("Initialized Log!");
	BG_INFO("Hello world!");

	auto app = Benga::CreateApplication();
	app->Run();
	delete app;
}

#endif