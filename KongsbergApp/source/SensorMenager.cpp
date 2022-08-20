#include "../headers/SensorMenager.hpp"

common::SensorMenager::SensorMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iMessageQueue* messageQueue)
{
	this->logger = logger;
	this->lifeCycleMenager = lifeCycleMenager;
	this->messageQueue = messageQueue;
	this->lifeCycleMenager->registry(this);

}

common::SensorMenager::~SensorMenager()
{

}

utils::Status common::SensorMenager::getStatus()
{
	return utils::Status::START;
}

utils::ErrorCode common::SensorMenager::setStatus(utils::Status status)
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::SensorMenager::run()
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::SensorMenager::registerSensor(iSensorMenager* sensorMenager)
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::SensorMenager::pushNotPreparedMessage(std::string message)
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::SensorMenager::runSensor()
{
	return utils::ErrorCode::NOK;
}