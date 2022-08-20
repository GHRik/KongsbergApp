#include "../headers/MessageQueue.hpp"

common::MessageQueue::~MessageQueue()
{

}

common::MessageQueue::MessageQueue(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager)
{
	this->logger = logger;
	this->lifeCycleMenager = lifeCycleMenager;
	lifeCycleMenager->registry(this);
}

utils::ErrorCode common::MessageQueue::setStatus(utils::Status status)
{
	return utils::ErrorCode();
}

utils::Status common::MessageQueue::getStatus()
{
	return utils::Status();
}

utils::ErrorCode common::MessageQueue::run()
{
	return utils::ErrorCode();
}

utils::ErrorCode common::MessageQueue::popQueue(utils::queue_id id, std::string message)
{
	return utils::ErrorCode();
}

utils::ErrorCode common::MessageQueue::pushQueue(utils::queue_id id, std::string message)
{
	return utils::ErrorCode();
}

