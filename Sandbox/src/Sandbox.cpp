#include <Benga.h>

#include "Imgui/imgui.h"

class ExampleLayer : public Benga::Layer {

public:
	ExampleLayer()
		: Layer("Example") {

	}

	void OnUpdate() override {

		if (Benga::Input::IsKeyPressed(BG_KEY_TAB))
			BG_TRACE("Tab key is pressed");
	}

	virtual void OnImGuiRender() override {

		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Benga::Event& event) override {

		if (event.GetEventType() == Benga::EventType::KeyPressed) {

			Benga::KeyPressedEvent& e = (Benga::KeyPressedEvent&)event;
			BG_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Benga::Application {

public:
	Sandbox() {

		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Benga::Application* Benga::CreateApplication() {

	return new Sandbox();
}