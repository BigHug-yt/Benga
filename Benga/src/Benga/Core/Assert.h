#pragma once

#include "Benga/Core/Base.h"
#include "Benga/Core/Log.h"
#include <filesystem>

#ifdef BG_ENABLE_ASSERTS

	#define BG_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { BG##type##ERROR(msg, __VA_ARGS__); BG_DEBUGBREAK(); } }
	#define BG_INTERNAL_ASSERT_WITH_MSG(type, check, ...) BG_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define BG_INTERNAL_ASSERT_NO_MSG(type, check) BG_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", BG_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define BG_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define BG_INTERNAL_ASSERT_GET_MACRO(...) BG_EXPAND_MACRO( BG_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, BG_INTERNAL_ASSERT_WITH_MSG, BG_INTERNAL_ASSERT_NO_MSG) )

	#define BG_ASSERT(...) BG_EXPAND_MACRO( BG_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define BG_CORE_ASSERT(...) BG_EXPAND_MACRO( BG_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define BG_ASSERT(...)
	#define BG_CORE_ASSERT(...)
#endif
