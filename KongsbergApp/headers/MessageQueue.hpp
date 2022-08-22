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

		utils::ErrorCode pushQueue(uint8_t id, int message);
		utils::ErrorCode popQueue(uint8_t id, int message);

		
	};
}