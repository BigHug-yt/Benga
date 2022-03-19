#pragma once

#ifdef BG_PLATFORM_WINDOWS
	#ifdef BG_BUILD_DLL
		#define BENGA_API __declspec(dllexport)
	#else
		#define BENGA_API __declspec(dllimport)
	#endif
#else
	#error Benga only supports Windows!
#endif

#define BIT(x) (1 << x)