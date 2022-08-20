#pragma once

#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../utils/ErrorCode.hpp"
#include "../utils/Status.hpp"

namespace common
{
	class Logger : public interface::iLogger, public interface::iLifeCycleService
	{
	public:
		Logger();
		virtual ~Logger();
		utils::ErrorCode logError(std::string tag, std::string message);
		utils::ErrorCode logWarn(std::string tag, std::string message);
		utils::ErrorCode logInfo(std::string tag, std::string message);
		utils::ErrorCode setStatus(utils::Status status);
		utils::Status getStatus();
		utils::ErrorCode run();
		void stop();
		void passLifeCycle(interface::iLifeCycleMenager* lifeCycleMenager);

	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		utils::Status status;

	};
}