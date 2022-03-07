#include <Benga.h>

class Sandbox : public Benga::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Benga::Application* Benga::CreateApplication() {

	return new Sandbox();
}