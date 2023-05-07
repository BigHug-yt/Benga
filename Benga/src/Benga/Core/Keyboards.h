#pragma once

#include "Benga/Core/KeyCodes.h"

namespace Benga {

	class QWERTYKeyboard {

	public:
		static int KeyCodeToglfw(KeyCode key) { return m_KeyCodeToglfw[key]; };
		static KeyCode glfwToKeyCode(int key) { return m_glfwToKeyCode[key]; };

		static bool KeyCodeRequiresShift(KeyCode key) { return std::count(m_RequireShift.begin(), m_RequireShift.end(), key); };
		static bool KeyCodeRequiresRightAlt(KeyCode key) { return std::count(m_RequireRightAlt.begin(), m_RequireRightAlt.end(), key); };
	private:
		static std::unordered_map<KeyCode, int> m_KeyCodeToglfw;
		static std::unordered_map<int, KeyCode> m_glfwToKeyCode;

		static std::vector<KeyCode> m_RequireShift;
		static std::vector<KeyCode> m_RequireRightAlt;
	};

	class BelgianPeriodKeyboard {

	public:
		static int KeyCodeToglfw(KeyCode key) { return m_KeyCodeToglfw[key]; };
		static KeyCode glfwToKeyCode(int key) { return m_glfwToKeyCode[key]; };

		static bool KeyCodeRequiresShift(KeyCode key) { return std::count(m_RequireShift.begin(), m_RequireShift.end(), key); };
		static bool KeyCodeRequiresRightAlt(KeyCode key) { return std::count(m_RequireRightAlt.begin(), m_RequireRightAlt.end(), key); }
	private:
		static std::unordered_map<KeyCode, int> m_KeyCodeToglfw;
		static std::unordered_map<int, KeyCode> m_glfwToKeyCode;

		static std::vector<KeyCode> m_RequireShift;
		static std::vector<KeyCode> m_RequireRightAlt;
	};
}
