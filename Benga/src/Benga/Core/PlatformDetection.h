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