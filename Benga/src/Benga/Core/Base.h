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

#define BG_EXPAND_MACRO(x) x
#define BG_STRINGIFY_MACRO(x) #x

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

#include "Benga/Core/Log.h"
#include "Benga/Core/Assert.h"
