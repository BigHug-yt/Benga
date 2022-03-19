#include "Application.h"

#include "Benga/Events/ApplicationEvent.h"
#include "Benga/Log.h"

namespace Benga {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		BG_TRACE(e);

		while (true);
	}
}