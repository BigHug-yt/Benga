#pragma once

#include <string>
#include <optional>

namespace Benga {

	class FileDialogs {

	public:
		// these return empty strings when cancelled
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);
	};
}
