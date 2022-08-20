#pragma once

#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../utils/ErrorCode.hpp"
#include "../utils/Status.hpp"

namespace common
{
	class Logger : public interface::iLogger
	{
	public:
		Logger();
		virtual ~Logger();
		utils::ErrorCode logError(std::string tag, std::string message);
		utils::ErrorCode logWarn(std::string tag, std::string message);
		utils::ErrorCode logInfo(std::string tag, std::string message);
	private:
		std::string logEvent(std::string tag, std::string message);

	};
}