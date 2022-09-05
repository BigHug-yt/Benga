#pragma once

#include <memory>

// Platform detection
#ifdef _WIN32
	// Windows x64/x86
	#ifdef _WIN64
		// Windows x64
		#define BG_PLATFORM_WINDOWS
	#else
		// Windows x86
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	* so we must check all of them (in order) to ensure we're running on MAC and not some other platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define BG_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define BG_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
// We also check __ANDROID__ before __LINUX__ as it has __linux__ defined
#elif defined(__ANDROID__)
	#define BG_PLATFORM_ANDROID
	#error "Android is not supported"
#elif defined(__linux__)
	#define BG_PLATFORM_LINUX
	#error "Linux is not supported"
#else
	#error "Unknown platform!"
#endif // End of Platform detection

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

#define BG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

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