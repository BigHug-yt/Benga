#pragma once

#include "Core.h"

#include "Window.h"
#include "Benga/Core/LayerStack.h"
#include "Benga/Events/Event.h"
#include "Benga/Events/ApplicationEvent.h"
#include "Benga/Events/KeyEvent.h"
#include "Benga/Events/MouseEvent.h"

#include "Benga/Core/Timestep.h"

namespace Benga {

	class Application {

	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();
}