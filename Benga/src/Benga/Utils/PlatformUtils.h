#pragma once

#include <string>

namespace Benga {

	class FileDialogs {

	public:
		// these return empty strings when cancelled
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);
	};

	class Time {

	public:
		static float GetTime();
	};
}
