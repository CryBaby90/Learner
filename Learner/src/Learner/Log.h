#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Learner
{
	class LEARNER_API Log
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

// Core log macros
#define LR_CORE_TRACE(...)::Learner::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LR_CORE_INFO(...)::Learner::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LR_CORE_WARN(...)::Learner::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LR_CORE_ERROR(...)::Learner::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LR_CORE_FATAL(...)::Learner::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LR_TRACE(...)::Learner::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LR_INFO(...)::Learner::Log::GetClientLogger()->info(__VA_ARGS__)
#define LR_WARN(...)::Learner::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LR_ERROR(...)::Learner::Log::GetClientLogger()->error(__VA_ARGS__)
#define LR_FATAL(...)::Learner::Log::GetClientLogger()->fatal(__VA_ARGS__)


