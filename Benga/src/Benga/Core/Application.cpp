#include "bgpch.h"
#include "Benga/Core/Application.h"

#include "Benga/Core/Log.h"

#include "Benga/Renderer/Renderer.h"

#include "Benga/Core/Input.h"

#include "Benga/Utils/PlatformUtils.h"

namespace Benga {

	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpec& spec)
		: m_Spec(spec) {

		BG_PROFILE_FUNCTION();

		BG_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		// Set working directory
		if (!m_Spec.WorkingDirectory.empty())
			std::filesystem::current_path(m_Spec.WorkingDirectory);

		m_Window = Window::Create(WindowProps(m_Spec.Name));
		m_Window->SetEventCallback(BG_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application() {

		BG_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}

	void Application::PushLayer(Layer* layer) {

		BG_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) {

		BG_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Close() {

		m_Running = false;
	}

	void Application::OnEvent(Event& e) {

		BG_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BG_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BG_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it) {

			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	void Application::Run() {

		BG_PROFILE_FUNCTION();

		while (m_Running) {

			BG_PROFILE_SCOPE("RunLoop");

			float time = Time::GetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized) {

				{
					BG_PROFILE_SCOPE("LayerStack OnUpdate");

					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}

				m_ImGuiLayer->Begin();
				{
					BG_PROFILE_SCOPE("LayerStack OnImGuiRender");

					for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
				}
				m_ImGuiLayer->End();
			}

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {

		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {

		BG_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0) {

			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}
}
