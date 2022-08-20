#pragma once

#include "../interfaces/iMessageQueue.hpp"
#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../interfaces/iListenerMenager.hpp"

namespace common
{
	class ListenerMenager : public interface::iListenerMenager, public interface::iLifeCycleService
	{
	public:
		ListenerMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iMessageQueue* messageQueue);
		~ListenerMenager();

		utils::ErrorCode setStatus(utils::Status status);
		utils::ErrorCode run();

		utils::ErrorCode registerListener(interface::iListenerMenager* listenerMenager);
		std::string popNotPreparedMessage();
		utils::ErrorCode pushPreparedMessage(std::string);
		utils::ErrorCode runListener();

	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		interface::iMessageQueue* messageQueue;
		utils::Status status;
	};
}