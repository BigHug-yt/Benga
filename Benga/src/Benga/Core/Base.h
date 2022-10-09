#pragma once

#include <memory>

#include "Benga/Core/PlatformDetection.h"

#ifdef BG_DEBUG
	#if defined(BG_PLATFORM_WINDOWS)
		#define BG_DEBUGBREAK() __debugbreak()
	#elif defined(BG_PLATFORM_LINUX)
		#include <signal.h>
		#define BG_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define BG_ENABLE_ASSERTS()
#else
	#define BG_DEBUGBREAK()
#endif

// TODO: enable BG_ASSERT to take in no arguments
#ifdef BG_ENABLE_ASSERTS
	#define BG_ASSERT(x, ...) { if(!(x)) { BG_ERROR("Assertion Failed: {0}", __VA_ARGS__); BG_DEBUGBREAK(); } }
	#define BG_CORE_ASSERT(x, ...) { if(!(x)) { BG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); BG_DEBUGBREAK(); } }
#else
	#define BG_ASSERT(x, ...)
	#define BG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BG_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Benga {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {

		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {

		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}