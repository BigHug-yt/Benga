#pragma once

namespace Benga {

	typedef enum class KeyCode : uint16_t {

		// From glfw3.h
		Space				= 32,
		Apostrophe			= 39, /* ' */
		Comma				= 44, /* , */
		Minus				= 45, /* - */
		Period				= 46, /* . */
		Slash				= 47, /* / */

		D0					= 48, /* 0 */
		D1					= 49, /* 1 */
		D2					= 50, /* 2 */
		D3					= 51, /* 3 */
		D4					= 52, /* 4 */
		D5					= 53, /* 5 */
		D6					= 54, /* 6 */
		D7					= 55, /* 7 */
		D8					= 56, /* 8 */
		D9					= 57, /* 9 */

		Semicolon			= 59, /* ; */
		Equal				= 61, /* = */

		A					= 65,
		B					= 66,
		C					= 67,
		D					= 68,
		E					= 69,
		F					= 70,
		G					= 71,
		H					= 72,
		I					= 73,
		J					= 74,
		K					= 75,
		L					= 76,
		M					= 77,
		N					= 78,
		O					= 79,
		P					= 80,
		Q					= 81,
		R					= 82,
		S					= 83,
		T					= 84,
		U					= 85,
		V					= 86,
		W					= 87,
		X					= 88,
		Y					= 89,
		Z					= 90,

		LeftBracket			= 91,  /* [ */
		Backslash			= 92,  /* \ */
		RightBracket		= 93,  /* ] */
		GraveAccent			= 96,  /* ` */
		
		World1				= 161, /* non-US #1 */
		World2				= 162, /* non-US #2 */

		/* Function keys*/
		Escape				= 256,
		Enter				= 257,
		Tab					= 258,
		Backspace			= 259,
		Insert				= 260,
		Delete				= 261,
		Right				= 262,
		Left				= 263,
		Down				= 264,
		Up					= 265,
		PageUp				= 266,
		PageDown			= 267,
		Home				= 268,
		End					= 269,
		CapsLock			= 280,
		ScrollLock			= 281,
		NumLock				= 282,
		PrintScreen			= 283,
		Pause				= 284,
		F1					= 290,
		F2					= 291,
		F3					= 292,
		F4					= 293,
		F5					= 294,
		F6					= 295,
		F7					= 296,
		F8					= 297,
		F9					= 298,
		F10					= 299,
		F11					= 300,
		F12					= 301,
		F13					= 302,
		F14					= 303,
		F15					= 304,
		F16					= 305,
		F17					= 306,
		F18					= 307,
		F19					= 308,
		F20					= 309,
		F21					= 310,
		F22					= 311,
		F23					= 312,
		F24					= 313,
		F25					= 314,

		/* Keypad */
		KP0					= 320,
		KP1					= 321,
		KP2					= 322,
		KP3					= 323,
		KP4					= 324,
		KP5					= 325,
		KP6					= 326,
		KP7					= 327,
		KP8					= 328,
		KP9					= 329,
		KPDecimal			= 330,
		KPDivide			= 331,
		KPMultiply			= 332,
		KPSubtract			= 333,
		KPAdd				= 334,
		KPEnter				= 335,
		KPEqual				= 336,
		
		LeftShift			= 340,
		LeftControl			= 341,
		LeftAlt				= 342,
		LeftSuper			= 343,
		RightShift			= 344,
		RightControl		= 345,
		RightAlt			= 346,
		RightSuper			= 347,
		Menu				= 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode) {

		os << static_cast<int32_t>(keyCode);
		return os;
	}
}


#define BG_KEY_SPACE              ::Benga::Key::Space
#define BG_KEY_APOSTROPHE         ::Benga::Key::Apostrophe  /* ' */
#define BG_KEY_COMMA              ::Benga::Key::Comma		/* , */
#define BG_KEY_MINUS              ::Benga::Key::Minus		/* - */
#define BG_KEY_PERIOD             ::Benga::Key::Period		/* . */
#define BG_KEY_SLASH              ::Benga::Key::Slash		/* / */
#define BG_KEY_0                  ::Benga::Key::D0
#define BG_KEY_1                  ::Benga::Key::D1
#define BG_KEY_2                  ::Benga::Key::D2
#define BG_KEY_3                  ::Benga::Key::D3
#define BG_KEY_4                  ::Benga::Key::D4
#define BG_KEY_5                  ::Benga::Key::D5
#define BG_KEY_6                  ::Benga::Key::D6
#define BG_KEY_7                  ::Benga::Key::D7
#define BG_KEY_8                  ::Benga::Key::D8
#define BG_KEY_9                  ::Benga::Key::D9
#define BG_KEY_SEMICOLON          ::Benga::Key::Semicolon	/* ; */
#define BG_KEY_EQUAL              ::Benga::Key::Equal		/* = */
#define BG_KEY_A                  ::Benga::Key::A
#define BG_KEY_B                  ::Benga::Key::B
#define BG_KEY_C                  ::Benga::Key::C
#define BG_KEY_D                  ::Benga::Key::D
#define BG_KEY_E                  ::Benga::Key::E
#define BG_KEY_F                  ::Benga::Key::F
#define BG_KEY_G                  ::Benga::Key::G
#define BG_KEY_H                  ::Benga::Key::H
#define BG_KEY_I                  ::Benga::Key::I
#define BG_KEY_J                  ::Benga::Key::J
#define BG_KEY_K                  ::Benga::Key::K
#define BG_KEY_L                  ::Benga::Key::L
#define BG_KEY_M                  ::Benga::Key::M
#define BG_KEY_N                  ::Benga::Key::N
#define BG_KEY_O                  ::Benga::Key::O
#define BG_KEY_P                  ::Benga::Key::P
#define BG_KEY_Q                  ::Benga::Key::Q
#define BG_KEY_R                  ::Benga::Key::R
#define BG_KEY_S                  ::Benga::Key::S
#define BG_KEY_T                  ::Benga::Key::T
#define BG_KEY_U                  ::Benga::Key::U
#define BG_KEY_V                  ::Benga::Key::V
#define BG_KEY_W                  ::Benga::Key::W
#define BG_KEY_X                  ::Benga::Key::X
#define BG_KEY_Y                  ::Benga::Key::Y
#define BG_KEY_Z                  ::Benga::Key::Z
#define BG_KEY_LEFT_BRACKET       ::Benga::Key::LeftBracket		/* [ */
#define BG_KEY_BACKSLASH          ::Benga::Key::Backslash		/* \ */
#define BG_KEY_RIGHT_BRACKET      ::Benga::Key::RightBracket	/* ] */
#define BG_KEY_GRAVE_ACCENT       ::Benga::Key::GraveAccent		/* ` */
#define BG_KEY_WORLD_1            ::Benga::Key::World1			/* non-US #1 */
#define BG_KEY_WORLD_2            ::Benga::Key::World2			/* non-US #2 */

/* Function keys */
#define BG_KEY_ESCAPE             ::Benga::Key::Escape		
#define BG_KEY_ENTER              ::Benga::Key::Enter		
#define BG_KEY_TAB                ::Benga::Key::Tab			
#define BG_KEY_BACKSPACE          ::Benga::Key::Backspace	
#define BG_KEY_INSERT             ::Benga::Key::Insert		
#define BG_KEY_DELETE             ::Benga::Key::Delete		
#define BG_KEY_RIGHT              ::Benga::Key::Right		
#define BG_KEY_LEFT               ::Benga::Key::Left		
#define BG_KEY_DOWN               ::Benga::Key::Down		
#define BG_KEY_UP                 ::Benga::Key::Up			
#define BG_KEY_PAGE_UP            ::Benga::Key::PageUp		
#define BG_KEY_PAGE_DOWN          ::Benga::Key::PageDown	
#define BG_KEY_HOME               ::Benga::Key::Home		
#define BG_KEY_END                ::Benga::Key::End			
#define BG_KEY_CAPS_LOCK          ::Benga::Key::CapsLock	
#define BG_KEY_SCROLL_LOCK        ::Benga::Key::ScrollLock	
#define BG_KEY_NUM_LOCK           ::Benga::Key::NumLock		
#define BG_KEY_PRINT_SCREEN       ::Benga::Key::PrintScreen	
#define BG_KEY_PAUSE              ::Benga::Key::Pause		
#define BG_KEY_F1                 ::Benga::Key::F1			
#define BG_KEY_F2                 ::Benga::Key::F2			
#define BG_KEY_F3                 ::Benga::Key::F3			
#define BG_KEY_F4                 ::Benga::Key::F4			
#define BG_KEY_F5                 ::Benga::Key::F5			
#define BG_KEY_F6                 ::Benga::Key::F6			
#define BG_KEY_F7                 ::Benga::Key::F7			
#define BG_KEY_F8                 ::Benga::Key::F8			
#define BG_KEY_F9                 ::Benga::Key::F9			
#define BG_KEY_F10                ::Benga::Key::F10			
#define BG_KEY_F11                ::Benga::Key::F11			
#define BG_KEY_F12                ::Benga::Key::F12			
#define BG_KEY_F13                ::Benga::Key::F13			
#define BG_KEY_F14                ::Benga::Key::F14			
#define BG_KEY_F15                ::Benga::Key::F15			
#define BG_KEY_F16                ::Benga::Key::F16			
#define BG_KEY_F17                ::Benga::Key::F17			
#define BG_KEY_F18                ::Benga::Key::F18			
#define BG_KEY_F19                ::Benga::Key::F19			
#define BG_KEY_F20                ::Benga::Key::F20			
#define BG_KEY_F21                ::Benga::Key::F21			
#define BG_KEY_F22                ::Benga::Key::F22			
#define BG_KEY_F23                ::Benga::Key::F23			
#define BG_KEY_F24                ::Benga::Key::F24			
#define BG_KEY_F25                ::Benga::Key::F25			
#define BG_KEY_KP_0               ::Benga::Key::KP0			
#define BG_KEY_KP_1               ::Benga::Key::KP1			
#define BG_KEY_KP_2               ::Benga::Key::KP2			
#define BG_KEY_KP_3               ::Benga::Key::KP3			
#define BG_KEY_KP_4               ::Benga::Key::KP4			
#define BG_KEY_KP_5               ::Benga::Key::KP5			
#define BG_KEY_KP_6               ::Benga::Key::KP6			
#define BG_KEY_KP_7               ::Benga::Key::KP7			
#define BG_KEY_KP_8               ::Benga::Key::KP8			
#define BG_KEY_KP_9               ::Benga::Key::KP9			
#define BG_KEY_KP_DECIMAL         ::Benga::Key::KPDecimal	
#define BG_KEY_KP_DIVIDE          ::Benga::Key::KPDivide	
#define BG_KEY_KP_MULTIPLY        ::Benga::Key::KPMultiply	
#define BG_KEY_KP_SUBTRACT        ::Benga::Key::KPSubtract	
#define BG_KEY_KP_ADD             ::Benga::Key::KPAdd		
#define BG_KEY_KP_ENTER           ::Benga::Key::KPEnter		
#define BG_KEY_KP_EQUAL           ::Benga::Key::KPEqual		
#define BG_KEY_LEFT_SHIFT         ::Benga::Key::LeftShift	
#define BG_KEY_LEFT_CONTROL       ::Benga::Key::LeftControl	
#define BG_KEY_LEFT_ALT           ::Benga::Key::LeftAlt		
#define BG_KEY_LEFT_SUPER         ::Benga::Key::LeftSuper	
#define BG_KEY_RIGHT_SHIFT        ::Benga::Key::RightShift	
#define BG_KEY_RIGHT_CONTROL      ::Benga::Key::RightControl
#define BG_KEY_RIGHT_ALT          ::Benga::Key::RightAlt	
#define BG_KEY_RIGHT_SUPER        ::Benga::Key::RightSuper	
#define BG_KEY_MENU               ::Benga::Key::Menu		

