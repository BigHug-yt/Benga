#pragma once

#include "Event.h"

#include <sstream>

namespace Benga {

	class BENGA_API KeyEvent : public Event {

	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		Event_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class BENGA_API KeyPressedEvent : public KeyEvent {

	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override {

			std::stringsteam ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class BENGA_API KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override {

			std::stringsteam ss;
			ss << "KeyPressedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};
}