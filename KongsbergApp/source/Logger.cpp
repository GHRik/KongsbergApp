#include "../headers/Logger.hpp"

common::Logger::Logger()
{
}

common::Logger::~Logger()
{
}


utils::ErrorCode common::Logger::logError(std::string tag, std::string message)
{
	return utils::ErrorCode::NOK;
}
utils::ErrorCode common::Logger::logWarn(std::string tag, std::string message)
{
	return utils::ErrorCode::NOK;
}
utils::ErrorCode common::Logger::logInfo(std::string tag, std::string message)
{
	return utils::ErrorCode::NOK;
}

utils::Status common::Logger::getStatus()
{
	return status;
}

utils::ErrorCode common::Logger::setStatus(utils::Status status)
{
	this->status = status;
	return utils::ErrorCode::OK;
}

utils::ErrorCode common::Logger::run()
{
	return utils::ErrorCode::NOK;
}

void common::Logger::stop()
{
}

void common::Logger::passLifeCycle(interface::iLifeCycleMenager* lifeCycleMenager)
{
}


