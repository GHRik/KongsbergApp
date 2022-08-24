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
		ListenerMenager() = delete;
		ListenerMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iConfigMenager* configLoader, interface::iMessageQueue* messageQueue);
		virtual ~ListenerMenager();

		utils::ErrorCode setStatus(utils::Status status) override;
		utils::ErrorCode run() override;

		utils::ErrorCode registerListener(interface::iListenerService* listenerService) override;
		int popNotPreparedMessage(uint8_t id) override;
		utils::ErrorCode runListener() override;
		utils::ErrorCode logOutput(const std::string &output) override;

	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		interface::iConfigMenager* configLoader;
		interface::iMessageQueue* messageQueue;

		std::vector<interface::iListenerService*> listenerWantToBeAlive;

		void deleteListeners();
	};
}