#include "../headers/Logger.hpp"
#include <iostream>

utils::ErrorCode common::Logger::logError(const std::string &tag, const std::string &message)
{
	std::cout << "ERROR: " << this->logEvent(tag, message);
	return utils::ErrorCode::OK;
}

utils::ErrorCode common::Logger::logInfo(const std::string &tag, const std::string &message)
{
	std::cout << "INFO: " << this->logEvent(tag, message);
	return utils::ErrorCode::OK;
}

std::string common::Logger::logEvent(const std::string &tag, const std::string &message) const
{
	std::string result = "";
	result += tag + "\t" + message + "\n";
	return result;

}


