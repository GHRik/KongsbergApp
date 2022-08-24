#pragma once

#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iMessageQueue.hpp"
#include "../interfaces/iLogger.hpp"
#include <vector>
#include "../interfaces/iConfigMenager.hpp"

namespace common
{
	class MessageQueue : public interface::iMessageQueue
	{
	public:
		explicit MessageQueue();
		virtual ~MessageQueue() = default;

		utils::ErrorCode pushQueue(uint8_t id, int message);
		int popQueue(uint8_t id);

		void stop();

		
	};
}