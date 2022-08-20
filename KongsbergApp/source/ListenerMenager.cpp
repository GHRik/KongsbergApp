#include "../headers/ListenerMenager.hpp"

common::ListenerMenager::ListenerMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iMessageQueue* messageQueue)
{
	this->logger = logger;
	this->lifeCycleMenager = lifeCycleMenager;
	this->messageQueue = messageQueue;
	this->lifeCycleMenager->registry(this);

}
common::ListenerMenager::~ListenerMenager()
{

}

utils::Status common::ListenerMenager::getStatus()
{
	return utils::Status::START;
}

utils::ErrorCode common::ListenerMenager::setStatus(utils::Status status)
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::ListenerMenager::run()
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::ListenerMenager::registerListener(iListenerMenager* sensorMenager)
{
	return utils::ErrorCode::NOK;
}

std::string common::ListenerMenager::popNotPreparedMessage()
{
	return "";
}

utils::ErrorCode common::ListenerMenager::pushPreparedMessage(std::string message)
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::ListenerMenager::runListener()
{
	return utils::ErrorCode::NOK;
}