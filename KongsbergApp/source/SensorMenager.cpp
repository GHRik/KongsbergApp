#include "../headers/SensorMenager.hpp"

common::SensorMenager::SensorMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iConfigMenager* configMenagfer, interface::iMessageQueue* messageQueue)
{
	this->logger = logger;
	this->lifeCycleMenager = lifeCycleMenager;
	this->messageQueue = messageQueue;
	this->configMenager = configMenager;
	this->lifeCycleMenager->registry(this);

}

common::SensorMenager::~SensorMenager()
{

}

utils::ErrorCode common::SensorMenager::run()
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::SensorMenager::setStatus(utils::Status status)
{
	return utils::ErrorCode();
}

utils::ErrorCode common::SensorMenager::registerSensor(iSensorMenager* sensorMenager)
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::SensorMenager::pushNotPreparedMessage(uint8_t id, int message)
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::SensorMenager::runSensor()
{
	return utils::ErrorCode::NOK;
}