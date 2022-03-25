#include "bgpch.h"
#include "Application.h"

#include "Benga/Events/ApplicationEvent.h"
#include "Benga/Log.h"

#include <GLFW/glfw3.h>

namespace Benga {

	Application::Application() {

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {

		while (m_Running) {

			glClearColor(1, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}