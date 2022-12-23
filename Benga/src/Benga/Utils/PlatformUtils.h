#pragma once

#include <string>
#include <optional>

namespace Benga {

	class FileDialogs {

	public:
		// these return empty strings when cancelled
		static std::optional<std::string> OpenFile(const char* filter);
		static std::optional<std::string> SaveFile(const char* filter);
	};
}
