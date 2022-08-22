#include "../headers/MessageQueue.hpp"

common::MessageQueue::~MessageQueue()
{

}

common::MessageQueue::MessageQueue()
{

}

int common::MessageQueue::popQueue(uint8_t id, int message)
{

	queue.at(id).pop_back();
	return queue.at(id).back();
}

utils::ErrorCode common::MessageQueue::pushQueue(uint8_t id, int message)
{
	queue.at(id).push_back(message);
	return utils::ErrorCode();
}

