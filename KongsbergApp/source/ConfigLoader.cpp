#include "../headers/ConfigLoader.hpp"

common::ConfigLoader::ConfigLoader(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager)
{
	this->logger = logger;
	this->lifeCycleMenager = lifeCycleMenager;
	this->lifeCycleMenager->registry(this);
}

common::ConfigLoader::~ConfigLoader()
{
}

uint8_t common::ConfigLoader::getNumberAliveSensors()
{
	return 0;
}

std::vector<int> common::ConfigLoader::getAliveSensorsID()
{
	return std::vector<int>();
}

std::vector<int> common::ConfigLoader::getAliveSensorsMin()
{
	return std::vector<int>();
}

std::vector<int> common::ConfigLoader::getAliveSensorsMax()
{
	return std::vector<int>();
}

std::vector<int> common::ConfigLoader::getAliveSensorsFreq()
{
	return std::vector<int>();
}

utils::ErrorCode common::ConfigLoader::setStatus(utils::Status status)
{
	return utils::ErrorCode();
}

utils::Status common::ConfigLoader::getStatus()
{
	return utils::Status();
}

utils::ErrorCode common::ConfigLoader::run()
{
	return utils::ErrorCode();
}
