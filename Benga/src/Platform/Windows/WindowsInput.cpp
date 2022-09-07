#include "bgpch.h"
#include "Benga/Core/Input.h"

#include "Benga/Core/Application.h"
#include <GLFW/glfw3.h>

namespace Benga {

	Keyboard Input::s_Keyboard = Keyboard::AZERTY;

	std::unordered_map<KeyCode, KeyCode> KeyCodeToAZERTY = {

		{ KeyCode::Space		, KeyCode::Space		},
		{ KeyCode::Apostrophe	, KeyCode::D4			},
		{ KeyCode::Comma		, KeyCode::M			},
		{ KeyCode::Minus		, KeyCode::Equal		},
		{ KeyCode::Period		, KeyCode::Comma		},
		{ KeyCode::Slash		, KeyCode::Period		},

		{ KeyCode::D0			, KeyCode::D0			},
		{ KeyCode::D1			, KeyCode::D1			},
		{ KeyCode::D2			, KeyCode::D2			},
		{ KeyCode::D3			, KeyCode::D3			},
		{ KeyCode::D4			, KeyCode::D4			},
		{ KeyCode::D5			, KeyCode::D5			},
		{ KeyCode::D6			, KeyCode::D6			},
		{ KeyCode::D7			, KeyCode::D7			},
		{ KeyCode::D8			, KeyCode::D8			},
		{ KeyCode::D9			, KeyCode::D9			},

		{ KeyCode::Semicolon	, KeyCode::Comma		},
		{ KeyCode::Equal		, KeyCode::Slash		},

		{ KeyCode::A			, KeyCode::Q			},
		{ KeyCode::B			, KeyCode::B			},
		{ KeyCode::C			, KeyCode::C			},
		{ KeyCode::D			, KeyCode::D			},
		{ KeyCode::E			, KeyCode::E			},
		{ KeyCode::F			, KeyCode::F			},
		{ KeyCode::G			, KeyCode::G			},
		{ KeyCode::H			, KeyCode::H			},
		{ KeyCode::I			, KeyCode::I			},
		{ KeyCode::J			, KeyCode::J			},
		{ KeyCode::K			, KeyCode::K			},
		{ KeyCode::L			, KeyCode::L			},
		{ KeyCode::M			, KeyCode::Semicolon	},
		{ KeyCode::N			, KeyCode::N			},
		{ KeyCode::O			, KeyCode::O			},
		{ KeyCode::P			, KeyCode::P			},
		{ KeyCode::Q			, KeyCode::A			},
		{ KeyCode::R			, KeyCode::R			},
		{ KeyCode::S			, KeyCode::S			},
		{ KeyCode::T			, KeyCode::T			},
		{ KeyCode::U			, KeyCode::U			},
		{ KeyCode::V			, KeyCode::V			},
		{ KeyCode::W			, KeyCode::Z			},
		{ KeyCode::X			, KeyCode::X			},
		{ KeyCode::Y			, KeyCode::Y			},
		{ KeyCode::Z			, KeyCode::W			},

		{ KeyCode::LeftBracket	, KeyCode::LeftBracket	},
		{ KeyCode::Backslash  	, KeyCode::World2		},
		{ KeyCode::RightBracket	, KeyCode::RightBracket	},
		{ KeyCode::GraveAccent	, KeyCode::Backslash	},

		{ KeyCode::World1		, KeyCode::World1		},
		{ KeyCode::World2		, KeyCode::World2		},

		{ KeyCode::Escape		, KeyCode::Escape		},
		{ KeyCode::Enter		, KeyCode::Enter		},
		{ KeyCode::Tab			, KeyCode::Tab			},
		{ KeyCode::Backspace	, KeyCode::Backspace	},
		{ KeyCode::Insert		, KeyCode::Insert		},
		{ KeyCode::Delete		, KeyCode::Delete		},
		{ KeyCode::Right		, KeyCode::Right		},
		{ KeyCode::Left			, KeyCode::Left			},
		{ KeyCode::Down			, KeyCode::Down			},
		{ KeyCode::Up			, KeyCode::Up			},
		{ KeyCode::PageUp		, KeyCode::PageUp		},
		{ KeyCode::PageDown		, KeyCode::PageDown		},
		{ KeyCode::Home			, KeyCode::Home			},
		{ KeyCode::End			, KeyCode::End			},
		{ KeyCode::CapsLock		, KeyCode::CapsLock,	},
		{ KeyCode::ScrollLock	, KeyCode::ScrollLock	},
		{ KeyCode::NumLock		, KeyCode::NumLock		},
		{ KeyCode::PrintScreen	, KeyCode::PrintScreen	},
		{ KeyCode::Pause		, KeyCode::Pause		},
		{ KeyCode::F1			, KeyCode::F1			},
		{ KeyCode::F2			, KeyCode::F2			},
		{ KeyCode::F3			, KeyCode::F3			},
		{ KeyCode::F4			, KeyCode::F4			},
		{ KeyCode::F5			, KeyCode::F5			},
		{ KeyCode::F6			, KeyCode::F6			},
		{ KeyCode::F7			, KeyCode::F7			},
		{ KeyCode::F8			, KeyCode::F8			},
		{ KeyCode::F9			, KeyCode::F9			},
		{ KeyCode::F10			, KeyCode::F10			},
		{ KeyCode::F11			, KeyCode::F11			},
		{ KeyCode::F12			, KeyCode::F12			},
		{ KeyCode::F13			, KeyCode::F13			},
		{ KeyCode::F14			, KeyCode::F14			},
		{ KeyCode::F15			, KeyCode::F15			},
		{ KeyCode::F16			, KeyCode::F16			},
		{ KeyCode::F17			, KeyCode::F17			},
		{ KeyCode::F18			, KeyCode::F18			},
		{ KeyCode::F19			, KeyCode::F19			},
		{ KeyCode::F20			, KeyCode::F20			},
		{ KeyCode::F21			, KeyCode::F21			},
		{ KeyCode::F22			, KeyCode::F22			},
		{ KeyCode::F23			, KeyCode::F23			},
		{ KeyCode::F24			, KeyCode::F24			},
		{ KeyCode::F25			, KeyCode::F25			},

		{ KeyCode::KP0			, KeyCode::KP0			},
		{ KeyCode::KP1			, KeyCode::KP1			},
		{ KeyCode::KP2			, KeyCode::KP2			},
		{ KeyCode::KP3			, KeyCode::KP3			},
		{ KeyCode::KP4			, KeyCode::KP4			},
		{ KeyCode::KP5			, KeyCode::KP5			},
		{ KeyCode::KP6			, KeyCode::KP6			},
		{ KeyCode::KP7			, KeyCode::KP7			},
		{ KeyCode::KP8			, KeyCode::KP8			},
		{ KeyCode::KP9			, KeyCode::KP9			},
		{ KeyCode::KPDecimal	, KeyCode::KPDecimal	},
		{ KeyCode::KPDivide		, KeyCode::KPDivide		},
		{ KeyCode::KPMultiply	, KeyCode::KPMultiply	},
		{ KeyCode::KPSubtract	, KeyCode::KPSubtract	},
		{ KeyCode::KPAdd		, KeyCode::KPAdd		},
		{ KeyCode::KPEnter		, KeyCode::KPEnter		},
		{ KeyCode::KPEqual		, KeyCode::KPEqual		},

		{ KeyCode::LeftShift	, KeyCode::LeftShift	},
		{ KeyCode::LeftControl	, KeyCode::LeftControl	},
		{ KeyCode::LeftAlt		, KeyCode::LeftAlt		},
		{ KeyCode::LeftSuper	, KeyCode::LeftSuper	},
		{ KeyCode::RightShift	, KeyCode::RightShift	},
		{ KeyCode::RightControl	, KeyCode::RightControl	},
		{ KeyCode::RightAlt		, KeyCode::RightAlt		},
		{ KeyCode::RightSuper	, KeyCode::RightSuper	},
		{ KeyCode::Menu			, KeyCode::Menu			}
	};

	std::unordered_map<KeyCode, KeyCode> AZERTYToKeyCode = {

		{ KeyCode::Space		, KeyCode::Space		},
		{ KeyCode::Apostrophe	, KeyCode::U			},
		{ KeyCode::Comma		, KeyCode::Semicolon	},
		{ KeyCode::Minus		, KeyCode::RightBracket	},
		{ KeyCode::Period		, KeyCode::Slash		},
		{ KeyCode::Slash		, KeyCode::Equal		},

		{ KeyCode::D0			, KeyCode::D0			},
		{ KeyCode::D1			, KeyCode::D1			},
		{ KeyCode::D2			, KeyCode::D2			},
		{ KeyCode::D3			, KeyCode::D3			},
		{ KeyCode::D4			, KeyCode::D4			},
		{ KeyCode::D5			, KeyCode::D5			},
		{ KeyCode::D6			, KeyCode::D6			},
		{ KeyCode::D7			, KeyCode::D7			},
		{ KeyCode::D8			, KeyCode::D8			},
		{ KeyCode::D9			, KeyCode::D9			},

		{ KeyCode::Semicolon	, KeyCode::M			},
		{ KeyCode::Equal		, KeyCode::Minus		},

		{ KeyCode::A			, KeyCode::Q			},
		{ KeyCode::B			, KeyCode::B			},
		{ KeyCode::C			, KeyCode::C			},
		{ KeyCode::D			, KeyCode::D			},
		{ KeyCode::E			, KeyCode::E			},
		{ KeyCode::F			, KeyCode::F			},
		{ KeyCode::G			, KeyCode::G			},
		{ KeyCode::H			, KeyCode::H			},
		{ KeyCode::I			, KeyCode::I			},
		{ KeyCode::J			, KeyCode::J			},
		{ KeyCode::K			, KeyCode::K			},
		{ KeyCode::L			, KeyCode::L			},
		{ KeyCode::M			, KeyCode::Comma		},
		{ KeyCode::N			, KeyCode::N			},
		{ KeyCode::O			, KeyCode::O			},
		{ KeyCode::P			, KeyCode::P			},
		{ KeyCode::Q			, KeyCode::A			},
		{ KeyCode::R			, KeyCode::R			},
		{ KeyCode::S			, KeyCode::S			},
		{ KeyCode::T			, KeyCode::T			},
		{ KeyCode::U			, KeyCode::U			},
		{ KeyCode::V			, KeyCode::V			},
		{ KeyCode::W			, KeyCode::Z			},
		{ KeyCode::Y			, KeyCode::Y			},
		{ KeyCode::X			, KeyCode::X			},
		{ KeyCode::Z			, KeyCode::W			},

		{ KeyCode::LeftBracket	, KeyCode::LeftBracket	},
		{ KeyCode::Backslash	, KeyCode::GraveAccent	},
		{ KeyCode::RightBracket	, KeyCode::RightBracket	},
		{ KeyCode::GraveAccent	, KeyCode::GraveAccent	},

		{ KeyCode::World1		, KeyCode::World1		},
		{ KeyCode::World2		, KeyCode::Backslash	},

		{ KeyCode::Escape		, KeyCode::Escape		},
		{ KeyCode::Enter		, KeyCode::Enter		},
		{ KeyCode::Tab			, KeyCode::Tab			},
		{ KeyCode::Backspace	, KeyCode::Backspace	},
		{ KeyCode::Insert		, KeyCode::Insert		},
		{ KeyCode::Delete		, KeyCode::Delete		},
		{ KeyCode::Right		, KeyCode::Right		},
		{ KeyCode::Left			, KeyCode::Left			},
		{ KeyCode::Down			, KeyCode::Down			},
		{ KeyCode::Up			, KeyCode::Up			},
		{ KeyCode::PageUp		, KeyCode::PageUp		},
		{ KeyCode::PageDown		, KeyCode::PageDown		},
		{ KeyCode::Home			, KeyCode::Home			},
		{ KeyCode::End			, KeyCode::End			},
		{ KeyCode::CapsLock		, KeyCode::CapsLock,	},
		{ KeyCode::ScrollLock	, KeyCode::ScrollLock	},
		{ KeyCode::NumLock		, KeyCode::NumLock		},
		{ KeyCode::PrintScreen	, KeyCode::PrintScreen	},
		{ KeyCode::Pause		, KeyCode::Pause		},
		{ KeyCode::F1			, KeyCode::F1			},
		{ KeyCode::F2			, KeyCode::F2			},
		{ KeyCode::F3			, KeyCode::F3			},
		{ KeyCode::F4			, KeyCode::F4			},
		{ KeyCode::F5			, KeyCode::F5			},
		{ KeyCode::F6			, KeyCode::F6			},
		{ KeyCode::F7			, KeyCode::F7			},
		{ KeyCode::F8			, KeyCode::F8			},
		{ KeyCode::F9			, KeyCode::F9			},
		{ KeyCode::F10			, KeyCode::F10			},
		{ KeyCode::F11			, KeyCode::F11			},
		{ KeyCode::F12			, KeyCode::F12			},
		{ KeyCode::F13			, KeyCode::F13			},
		{ KeyCode::F14			, KeyCode::F14			},
		{ KeyCode::F15			, KeyCode::F15			},
		{ KeyCode::F16			, KeyCode::F16			},
		{ KeyCode::F17			, KeyCode::F17			},
		{ KeyCode::F18			, KeyCode::F18			},
		{ KeyCode::F19			, KeyCode::F19			},
		{ KeyCode::F20			, KeyCode::F20			},
		{ KeyCode::F21			, KeyCode::F21			},
		{ KeyCode::F22			, KeyCode::F22			},
		{ KeyCode::F23			, KeyCode::F23			},
		{ KeyCode::F24			, KeyCode::F24			},
		{ KeyCode::F25			, KeyCode::F25			},

		{ KeyCode::KP0			, KeyCode::KP0			},
		{ KeyCode::KP1			, KeyCode::KP1			},
		{ KeyCode::KP2			, KeyCode::KP2			},
		{ KeyCode::KP3			, KeyCode::KP3			},
		{ KeyCode::KP4			, KeyCode::KP4			},
		{ KeyCode::KP5			, KeyCode::KP5			},
		{ KeyCode::KP6			, KeyCode::KP6			},
		{ KeyCode::KP7			, KeyCode::KP7			},
		{ KeyCode::KP8			, KeyCode::KP8			},
		{ KeyCode::KP9			, KeyCode::KP9			},
		{ KeyCode::KPDecimal	, KeyCode::KPDecimal	},
		{ KeyCode::KPDivide		, KeyCode::KPDivide		},
		{ KeyCode::KPMultiply	, KeyCode::KPMultiply	},
		{ KeyCode::KPSubtract	, KeyCode::KPSubtract	},
		{ KeyCode::KPAdd		, KeyCode::KPAdd		},
		{ KeyCode::KPEnter		, KeyCode::KPEnter		},
		{ KeyCode::KPEqual		, KeyCode::KPEqual		},

		{ KeyCode::LeftShift	, KeyCode::LeftShift	},
		{ KeyCode::LeftControl	, KeyCode::LeftControl	},
		{ KeyCode::LeftAlt		, KeyCode::LeftAlt		},
		{ KeyCode::LeftSuper	, KeyCode::LeftSuper	},
		{ KeyCode::RightShift	, KeyCode::RightShift	},
		{ KeyCode::RightControl	, KeyCode::RightControl	},
		{ KeyCode::RightAlt		, KeyCode::RightAlt		},
		{ KeyCode::RightSuper	, KeyCode::RightSuper	},
		{ KeyCode::Menu			, KeyCode::Menu			}
	};

	bool Input::IsKeyPressed(KeyCode key) {

		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(KeyCodeToglfw(key)));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(MouseCode button) {

		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return state == GLFW_PRESS;
	}

	std::pair<float, float> Input::GetMousePosition() {

		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float Input::GetMouseX() {

		auto [x, y] = GetMousePosition();
		return x;
	}

	float Input::GetMouseY() {

		auto [x, y] = GetMousePosition();
		return y;
	}

	void Input::SetKeyboard(Keyboard keyboard) {

		s_Keyboard = keyboard;
	}

	KeyCode Input::KeyCodeToglfw(KeyCode key) {

		switch (s_Keyboard) {

			case Keyboard::QWERTY:	return key;
			case Keyboard::AZERTY:	return KeyCodeToAZERTY[key];
		}
	}

	KeyCode Input::glfwToKeyCode(KeyCode key) {

		switch (s_Keyboard) {

			case Keyboard::QWERTY:	return key;
			case Keyboard::AZERTY:	return AZERTYToKeyCode[key];
		}
	}

}