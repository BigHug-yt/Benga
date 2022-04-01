#include <Benga.h>

class ExampleLayer : public Benga::Layer {

public:
	ExampleLayer()
		: Layer("Example") {

	}

	void OnUpdate() override {

		BG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Benga::Event& event) override {

		BG_TRACE("{0}", event);
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