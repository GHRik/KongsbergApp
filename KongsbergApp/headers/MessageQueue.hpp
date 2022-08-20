#pragma once

#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iMessageQueue.hpp"
#include "../interfaces/iLogger.hpp"
#include <vector>

namespace common
{
	class MessageQueue : public interface::iLifeCycleService, public interface::iMessageQueue
	{
	public:
		MessageQueue(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager);
		virtual ~MessageQueue();;
		utils::ErrorCode run();

		utils::ErrorCode pushQueue(utils::queue_id id, std::string message);
		utils::ErrorCode popQueue(utils::queue_id id, std::string message);

		std::vector<std::string> queueNotPrepare;
		std::vector<std::string> queuePrepared;


	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		utils::Status status;
	};
}