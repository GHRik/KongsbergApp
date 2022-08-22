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
	switch (status)
	{
	case utils::Status::INIT:
		this->status = utils::Status::INIT;
		break;
	case utils::Status::START:
		this->status = utils::Status::START;
		this->run();
		break;
	case utils::Status::WORK:
		this->status = utils::Status::WORK;
		break;
	case utils::Status::STOP:
		this->status = utils::Status::STOP;
		break;

	}
	return utils::ErrorCode::OK;
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