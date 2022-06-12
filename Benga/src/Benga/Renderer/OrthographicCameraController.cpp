#include "bgpch.h"
#include "OrthographicCameraController.h"

#include "Benga/Core/Input.h"
#include "Benga/Core/KeyCodes.h"

namespace Benga {

	OrthoGraphicCameraController::OrthoGraphicCameraController(float aspectRatio, bool rotation)
		: m_AspectRatio(aspectRatio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation) {

	}

	void OrthoGraphicCameraController::OnUpdate(Timestep ts) {

		if (Input::IsKeyPressed(BG_KEY_A))
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;

		else if (Input::IsKeyPressed(BG_KEY_D))
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;

		if (Input::IsKeyPressed(BG_KEY_S))
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;

		else if (Input::IsKeyPressed(BG_KEY_W))
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;

		if (m_Rotation) {
			if (Input::IsKeyPressed(BG_KEY_Q))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			if (Input::IsKeyPressed(BG_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed * ts;

			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CameraPosition);

		m_CameraTranslationSpeed = m_ZoomLevel;
	}

	void OrthoGraphicCameraController::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(BG_BIND_EVENT_FN(OrthoGraphicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(BG_BIND_EVENT_FN(OrthoGraphicCameraController::OnWindowResized));
	}

	bool OrthoGraphicCameraController::OnMouseScrolled(MouseScrolledEvent& e) {

		m_ZoomLevel -= e.GetYOffset() * 0.25f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool OrthoGraphicCameraController::OnWindowResized(WindowResizeEvent& e) {

		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
}