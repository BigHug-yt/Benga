#pragma once

#include "Benga/Core/KeyCodes.h"

namespace Benga {

	class QWERTYKeyboard {

	public:
		static int KeyCodeToglfw(KeyCode key) { return m_KeyCodeToglfw[key]; };
		static KeyCode glfwToKeyCode(int key) { return m_glfwToKeyCode[key]; };
	private:
		static std::unordered_map<KeyCode, int> m_KeyCodeToglfw;
		static std::unordered_map<int, KeyCode> m_glfwToKeyCode;
	};

	class BelgianPeriodKeyboard {

	public:
		static int KeyCodeToglfw(KeyCode key) { return m_KeyCodeToglfw[key]; };
		static KeyCode glfwToKeyCode(int key) { return m_glfwToKeyCode[key]; };
	private:
		static std::unordered_map<KeyCode, int> m_KeyCodeToglfw;
		static std::unordered_map<int, KeyCode> m_glfwToKeyCode;
	};
}
