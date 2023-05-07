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
		static bool IsKeyPressed(KeyCode key, bool exact = false);
		static bool IsKeyEqualTo(KeyCode a, KeyCode b);
		static bool IsKeyEquivalentTo(KeyCode a, KeyCode b);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

		static void SetKeyboard(Keyboard keyboard);
		static Keyboard GetKeyboard() { return m_Keyboard; }

		static int KeyCodeToglfw(KeyCode key);
		static KeyCode glfwToKeyCode(int key);

		static bool KeyCodeRequiresShift(KeyCode key);
		static bool KeyCodeRequiresRightAlt(KeyCode key);
	private:
		static Keyboard m_Keyboard;
	};

}
