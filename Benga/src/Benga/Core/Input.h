#pragma once

#include <glm/glm.hpp>

#include "Benga/Core/KeyCodes.h"
#include "Benga/Core/MouseCodes.h"

namespace Benga {

	enum class Keyboard {

		BelgianPeriod,
		QWERTY
	};

	class Input {

	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

		static void SetKeyboard(Keyboard keyboard);
		static Keyboard GetKeyboard() { return m_Keyboard; }

		static int KeyCodeToglfw(KeyCode key);
		static KeyCode glfwToKeyCode(int key);
	private:
		static Keyboard m_Keyboard;
	};

}
