#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Benga {

	class BENGA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core Logs
#define BG_CORE_TRACE(...)   ::Benga::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BG_CORE_INFO(...)    ::Benga::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BG_CORE_WARN(...)    ::Benga::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BG_CORE_ERROR(...)   ::Benga::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BG_CORE_FATAL(...)   ::Benga::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Logs
#define BG_TRACE(...)        ::Benga::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BG_INFO(...)         ::Benga::Log::GetClientLogger()->info(__VA_ARGS__)
#define BG_WARN(...)         ::Benga::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BG_ERROR(...)        ::Benga::Log::GetClientLogger()->error(__VA_ARGS__)
#define BG_FATAL(...)        ::Benga::Log::GetClientLogger()->fatal(__VA_ARGS__)