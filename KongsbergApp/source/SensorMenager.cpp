#include "../headers/SensorMenager.hpp"

common::SensorMenager::SensorMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iConfigMenager* configLoader, interface::iMessageQueue* messageQueue)
{
	this->logger = logger;
	this->lifeCycleMenager = lifeCycleMenager;
	this->messageQueue = messageQueue;
	this->configLoader = configLoader;
	this->lifeCycleMenager->registry(this);

}

common::SensorMenager::~SensorMenager()
{
	for (int i = 0; i < sensorsWantToBeAlive.size(); ++i)
	{
		if (sensorsWantToBeAlive.at(i) != nullptr)
		{
			delete sensorsWantToBeAlive.at(i);
		}
	}

}

utils::ErrorCode common::SensorMenager::run()
{
		for (int i = 0; i < sensorsWantToBeAlive.size(); ++i)
		{
			sensorsWantToBeAlive.at(i)->setStatus(utils::Status::START);
		}
		return utils::ErrorCode::OK;
}

utils::ErrorCode common::SensorMenager::setStatus(utils::Status status)
{
	switch (status)
	{
	case utils::Status::INIT:
		this->status = utils::Status::INIT;
		for (int i = 0; i < configLoader->getNumberAliveSensors(); ++i)
		{
			int id = configLoader->getAliveSensorsID().at(i);
			int freq = configLoader->getAliveSensorsFreq().at(i);
			int minRange = configLoader->getAliveSensorsMin().at(i);
			int maxRange = configLoader->getAliveSensorsMax().at(i);
			sensorLayer::Sensor* sensor = new sensorLayer::Sensor(this, id, freq, minRange, maxRange);
		}
		break;
	case utils::Status::START:
		this->status = utils::Status::START;
		this->run();
		break;
	case utils::Status::WORK:
		this->status = utils::Status::WORK;
		for (int i = 0; i < sensorsWantToBeAlive.size(); ++i)
		{
			sensorsWantToBeAlive.at(i)->setStatus(utils::Status::WORK);
		}
		break;
	case utils::Status::STOP:
		this->status = utils::Status::STOP;
		for (int i = 0; i < sensorsWantToBeAlive.size(); ++i)
		{
			sensorsWantToBeAlive.at(i)->setStatus(utils::Status::STOP);
		}
		for (int i = 0; i < sensorsWantToBeAlive.size(); ++i)
		{
			if (sensorsWantToBeAlive.at(i) != nullptr)
			{
				delete sensorsWantToBeAlive.at(i);
			}
		}
		sensorsWantToBeAlive.clear();
		break;

	}
	return utils::ErrorCode::OK;
}

utils::ErrorCode common::SensorMenager::registerSensor(interface::iSensorService* sensorService)
{
	sensorsWantToBeAlive.push_back(sensorService);
	return utils::ErrorCode::OK;
}

utils::ErrorCode common::SensorMenager::pushNotPreparedMessage(uint8_t id, int message)
{
	return messageQueue->pushQueue(id, message);
}

utils::ErrorCode common::SensorMenager::runSensor()
{
	for (int i = 0; i < sensorsWantToBeAlive.size(); ++i)
	{
		sensorsWantToBeAlive.at(i)->setStatus(utils::Status::INIT);
	}
	return utils::ErrorCode::OK;
}