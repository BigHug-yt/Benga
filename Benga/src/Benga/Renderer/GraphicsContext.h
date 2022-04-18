#pragma once

namespace Benga {

	class GraphicsContext {

	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}