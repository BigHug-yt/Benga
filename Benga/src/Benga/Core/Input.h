#pragma once

#include "Benga/Core/Base.h"
#include "Benga/Core/KeyCodes.h"
#include "Benga/Core/MouseCodes.h"

namespace Benga {

	enum class Keyboard {

		QWERTY,
		AZERTY
	};

	class Input {

	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

		static void SetKeyboard(Keyboard keyboard);
		static Keyboard GetKeyboard() { return s_Keyboard; }

		static KeyCode KeyCodeToglfw(KeyCode key);
		static KeyCode glfwToKeyCode(KeyCode key);
	private:
		static Keyboard s_Keyboard;
	};

}