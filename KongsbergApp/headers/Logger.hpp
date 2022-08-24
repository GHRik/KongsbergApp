/**
* @File Logger.hpp
* @brief: this module is responsible for logging on this moment on stdout.
*
* @Owner Damian Panasiuk
*/

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
		explicit Logger() = default;
		virtual ~Logger() = default;
		utils::ErrorCode logError(const std::string &tag, const std::string &message) override;
		utils::ErrorCode logInfo(const std::string &tag, const std::string &message) override;
	private:
		std::string logEvent(const std::string &tag, const std::string &message) const;

	};
}