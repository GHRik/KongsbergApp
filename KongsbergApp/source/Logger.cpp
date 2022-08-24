#include "../headers/Logger.hpp"
#include <iostream>

common::Logger::Logger()
{
}

common::Logger::~Logger()
{
}


utils::ErrorCode common::Logger::logError(std::string tag, std::string message)
{
	std::cout << "ERROR: " << this->logEvent(tag, message);
	return utils::ErrorCode::OK;
}
utils::ErrorCode common::Logger::logWarn(std::string tag, std::string message)
{
	std::cout << "WARM: " << this->logEvent(tag, message);
	return utils::ErrorCode::OK;
}
utils::ErrorCode common::Logger::logInfo(std::string tag, std::string message)
{
	std::cout << "INFO: " << this->logEvent(tag, message);
	return utils::ErrorCode::OK;
}

std::string common::Logger::logEvent(std::string &tag, std::string &message) const
{
	std::string result = "";
	result += tag + "\t" + message + "\n";
	return result;

}


