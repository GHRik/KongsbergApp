#include "../headers/MessageQueue.hpp"


common::MessageQueue::MessageQueue()
{
	queue.resize(256);
	for (int i = 0; i < 256; i++)
	{
		queue.at(i).reserve(10000);
	}

}

int common::MessageQueue::popQueue(uint8_t id)
{
	if (queue.at(id).empty())
	{
		return 0;
	}
	if (queue.at(id).size() == 1)
	{
		return queue.at(id).back();
	}

	int result = queue.at(id).back();
	queue.at(id).pop_back();
	return result;
}

utils::ErrorCode common::MessageQueue::pushQueue(uint8_t id, int message)
{
	queue.at(id).push_back(message);
	return utils::ErrorCode();
}

void common::MessageQueue::stop()
{
	for (int i = 0; i < 256; i++)
	{
		queue.at(i).clear();
	}
}

