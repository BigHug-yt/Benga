#include "bgpch.h"
#include "Benga/Core/Input.h"

#include "Benga/Core/Application.h"

#include "Benga/Core/Keyboards.h"

#include <GLFW/glfw3.h>

namespace Benga {

	Keyboard Input::m_Keyboard = Keyboard::BelgianPeriod;

	bool Input::IsKeyPressed(KeyCode key) {

		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int glfwKey = KeyCodeToglfw(key);
		auto state = glfwGetKey(window, (glfwKey));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(MouseCode button) {

		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::GetMousePosition() {

		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float Input::GetMouseX() {

		return GetMousePosition().x;
	}

	float Input::GetMouseY() {

		return GetMousePosition().y;
	}

	void Input::SetKeyboard(Keyboard keyboard) {

		m_Keyboard = keyboard;
	}

	int Input::KeyCodeToglfw(KeyCode key) {

		switch (m_Keyboard) {

			case Keyboard::QWERTY:	return QWERTYKeyboard::KeyCodeToglfw(key);
			case Keyboard::BelgianPeriod:	return BelgianPeriodKeyboard::KeyCodeToglfw(key);
		}

		BG_CORE_ASSERT(false, "Unknown Keyboard!");
		return 0;
	}

	KeyCode Input::glfwToKeyCode(int key) {

		switch (m_Keyboard) {

			case Keyboard::QWERTY:	return QWERTYKeyboard::glfwToKeyCode(key);
			case Keyboard::BelgianPeriod:	return BelgianPeriodKeyboard::glfwToKeyCode(key);
		}

		BG_CORE_ASSERT(false, "Unknown Keyboard!");
		return (KeyCode)0;
	}

}
