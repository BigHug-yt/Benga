#pragma once

#include "Benga/Layer.h"

#include "Benga/Events/KeyEvent.h"
#include "Benga/Events/MouseEvent.h"
#include "Benga/Events/ApplicationEvent.h"

namespace Benga {

	class BENGA_API ImGuiLayer : public Layer {

	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}