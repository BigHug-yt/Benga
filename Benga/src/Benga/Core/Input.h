#pragma once

#include "Benga/Core/Base.h"
#include "Benga/Core/KeyCodes.h"
#include "Benga/Core/MouseCodes.h"

namespace Benga {

	class Input {

	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}