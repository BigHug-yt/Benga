#include <Benga.h>

class ExampleLayer : public Benga::Layer {

public:
	ExampleLayer()
		: Layer("Example") {

	}

	void OnUpdate() override {

		if (Benga::Input::IsKeyPressed(BG_KEY_TAB))
			BG_TRACE("Tab key is pressed (poll)");
	}

	void OnEvent(Benga::Event& event) override {
		
		if (event.GetEventType() == Benga::EventType::KeyPressed) {
		
			Benga::KeyPressedEvent& e = (Benga::KeyPressedEvent&)event;
			if (e.GetKeyCode() == BG_KEY_TAB)
				BG_TRACE("Tab key is pressed (event)");
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