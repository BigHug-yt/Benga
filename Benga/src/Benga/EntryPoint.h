#pragma once

#ifdef BG_PLATFORM_WINDOWS

extern Benga::Application* Benga::CreateApplication();

int main(int argc, char** argv) {
	auto app = Benga::CreateApplication();
	app->Run();
	delete app;
}

#endif