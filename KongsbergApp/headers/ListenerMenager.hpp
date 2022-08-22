#pragma once

#include "../interfaces/iMessageQueue.hpp"
#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../interfaces/iListenerService.hpp"
#include "../interfaces/iListenerMenager.hpp"
#include "../interfaces/iConfigMenager.hpp"
#include "../headers/Listener.hpp"

namespace common
{
	class ListenerMenager : public interface::iListenerMenager, public interface::iLifeCycleService
	{
	public:
		ListenerMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iConfigMenager* configLoader, interface::iMessageQueue* messageQueue);
		~ListenerMenager();

		utils::ErrorCode setStatus(utils::Status status);
		utils::ErrorCode run();

		utils::ErrorCode registerListener(interface::iListenerService* listenerService);
		int popNotPreparedMessage(uint8_t id);
		utils::ErrorCode pushPreparedMessage(uint8_t id, int message);
		utils::ErrorCode runListener();

	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		interface::iConfigMenager* configLoader;
		interface::iMessageQueue* messageQueue;

		std::vector<interface::iListenerService*> listenerWantToBeAlive;
	};
}