#pragma once

#include "Core.h"

namespace Benga {

	class BENGA_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}