#include "../headers/MessageQueue.hpp"

common::MessageQueue::~MessageQueue()
{

}

common::MessageQueue::MessageQueue()
{

}

utils::ErrorCode common::MessageQueue::popQueue(utils::queue_id id, std::string message)
{
	return utils::ErrorCode();
}

utils::ErrorCode common::MessageQueue::pushQueue(utils::queue_id id, std::string message)
{
	return utils::ErrorCode();
}

