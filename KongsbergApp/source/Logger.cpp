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


