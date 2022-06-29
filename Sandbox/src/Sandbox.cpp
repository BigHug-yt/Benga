#include <Benga.h>
#include <Benga/Core/EntryPoint.h>

#include "Sandbox2D.h"

#include "ExampleLayer.h"

class Sandbox : public Benga::Application {

public:
	Sandbox() {
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox() {

	}
};

Benga::Application* Benga::CreateApplication() {

	return new Sandbox();
}