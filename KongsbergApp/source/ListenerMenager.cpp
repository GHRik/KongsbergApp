#include "../headers/ListenerMenager.hpp"

common::ListenerMenager::ListenerMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iConfigMenager* configLoader, interface::iMessageQueue* messageQueue)
{
	this->logger = logger;
	this->lifeCycleMenager = lifeCycleMenager;
	this->configLoader = configLoader;
	this->messageQueue = messageQueue;
	this->lifeCycleMenager->registry(this);
}
common::ListenerMenager::~ListenerMenager()
{

}

utils::ErrorCode common::ListenerMenager::run()
{
	for (int i = 0; i < listenerWantToBeAlive.size(); ++i)
	{
		listenerWantToBeAlive.at(i)->setStatus(utils::Status::START);
	}
	return utils::ErrorCode::OK;
}

utils::ErrorCode common::ListenerMenager::setStatus(utils::Status status)
{
	switch (status)
	{
	case utils::Status::INIT:
		this->status = utils::Status::INIT;
		for (int i = 0; i < configLoader->getNumberAliveSensors(); ++i)
		{
			std::string name = configLoader->getAliveSensorsName().at(i);
			int id = configLoader->getAliveSensorsID().at(i);
			int min = configLoader->getAliveSensorsMin().at(i);
			int max = configLoader->getAliveSensorsMax().at(i);
			int freq = configLoader->getAliveSensorsFreq().at(i);
			listenerLayer::Listener* listener = new listenerLayer::Listener(this, name, max, min, freq);
		}
		runListener();
		break;
	case utils::Status::START:
		this->status = utils::Status::START;
		this->run();
		break;
	case utils::Status::WORK:
		this->status = utils::Status::WORK;
		for (int i = 0; i < listenerWantToBeAlive.size(); ++i)
		{
			listenerWantToBeAlive.at(i)->setStatus(utils::Status::WORK);
		}

		break;
	case utils::Status::STOP:
		this->status = utils::Status::STOP;
		for (int i = 0; i < listenerWantToBeAlive.size(); ++i)
		{
			listenerWantToBeAlive.at(i)->setStatus(utils::Status::STOP);
		}
		/*for (int i = 0; i < listenerWantToBeAlive.size(); ++i)
		{
			delete listenerWantToBeAlive.at(i);
		}*/
		break;

	}
	return utils::ErrorCode::OK;
}


utils::ErrorCode common::ListenerMenager::registerListener(interface::iListenerService* listenerService)
{
	listenerWantToBeAlive.push_back(listenerService);
	return utils::ErrorCode::OK;
}

int common::ListenerMenager::popNotPreparedMessage(uint8_t id)
{
	return messageQueue->popQueue(id);
}

utils::ErrorCode common::ListenerMenager::pushPreparedMessage(uint8_t id, int message)
{
	return messageQueue->pushQueue(id, message);
}

utils::ErrorCode common::ListenerMenager::runListener()
{
	for (int i = 0; i < listenerWantToBeAlive.size(); ++i)
	{
		listenerWantToBeAlive.at(i)->setStatus(utils::Status::INIT);
	}
	return utils::ErrorCode::OK;
}