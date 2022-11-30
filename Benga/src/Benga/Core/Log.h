#pragma once

#include "Benga/Core/Base.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Benga {

	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;

	};
}

// Core Logs
#define BG_CORE_TRACE(...)		::Benga::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BG_CORE_INFO(...)		::Benga::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BG_CORE_WARN(...)		::Benga::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BG_CORE_ERROR(...)		::Benga::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BG_CORE_CRITICAL(...)	::Benga::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Logs
#define BG_TRACE(...)			::Benga::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BG_INFO(...)			::Benga::Log::GetClientLogger()->info(__VA_ARGS__)
#define BG_WARN(...)			::Benga::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BG_ERROR(...)			::Benga::Log::GetClientLogger()->error(__VA_ARGS__)
#define BG_CRITICAL(...)		::Benga::Log::GetClientLogger()->critical(__VA_ARGS__)
