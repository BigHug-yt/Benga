#pragma once

#include <memory>

#ifdef BG_PLATFORM_WINDOWS
	#if BG_DYNAMIC_LINK
		#ifdef BG_BUILD_DLL
			#define BENGA_API __declspec(dllexport)
		#else
			#define BENGA_API __declspec(dllimport)
		#endif
	#else
		#define BENGA_API
	#endif
#else
	#error Benga only supports Windows!
#endif

#ifdef BG_DEBUG
	#define BG_ENABLE_ASSERTS
#endif

#ifdef BG_ENABLE_ASSERTS
	#define BG_ASSERT(x, ...) { if(!(x)) { BG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BG_CORE_ASSERT(x, ...) { if(!(x)) { BG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BG_ASSERT(x, ...)
	#define BG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Benga {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}