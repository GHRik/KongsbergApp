#pragma once

#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iMessageQueue.hpp"
#include "../interfaces/iLogger.hpp"
#include <vector>

namespace common
{
	class MessageQueue : public interface::iMessageQueue
	{
	public:
		MessageQueue();
		virtual ~MessageQueue();;

		utils::ErrorCode pushQueue(utils::queue_id id, std::string message);
		utils::ErrorCode popQueue(utils::queue_id id, std::string message);

		std::vector<std::string> queueNotPrepare;
		std::vector<std::string> queuePrepared;
	};
}