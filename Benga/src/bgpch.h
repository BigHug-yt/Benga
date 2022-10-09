#pragma once

#include "Benga/Core//PlatformDetection.h"

#ifdef BG_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Benga/Core/Base.h"

#include "Benga/Core/Log.h"

#include "Benga/Debug/Instrumentor.h"

#ifdef BG_PLATFORM_WINDOWS
	#include <Windows.h>
#endif