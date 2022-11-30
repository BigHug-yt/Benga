#pragma once

#include "Benga/Core/Layer.h"

#include "Benga/Events/ApplicationEvent.h"
#include "Benga/Events/KeyEvent.h"
#include "Benga/Events/MouseEvent.h"

namespace Benga {

	class ImGuiLayer : public Layer {

	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}
