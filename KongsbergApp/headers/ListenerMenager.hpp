/**
* @File ConfigLoader.hpp
* @brief: responsible for create and menage listeners
*
* @Owner Damian Panasiuk
*/

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

		/**
		* LifeCycle module can menage status with this function.
		**/
		utils::ErrorCode setStatus(utils::Status status) override;

		/**
		* Routine of ListenerMenager Like turn on all listeners.
		* ListenerMenager routine will run in main thread.
		**/
		utils::ErrorCode run() override;

		/**
		* On this function listeners can registry to listenerMenager.
		* Registry mean add to vector. With pointers on listeners
		* listenerMenager can easly menage listeners like destroy, create etc.
		**/
		utils::ErrorCode registerListener(interface::iListenerService* listenerService) override;

		/**
		* On this function listeners by listenerMenager get data from
		* cyclicBuffor. 
		* @param: bufor id
		* @return not wrapped data from buffor it
		**/
		int popNotPreparedMessage(uint8_t id) override;

		/**
		* This function used by listenerMenager
		* set all listeners in work mode.
		**/
		utils::ErrorCode runListener() override;
		/**
		* By this function listeners by listenerMenager
		* can send wrapped data on logger to log results.
		* @param: wrapped data to send on logger to log
		**/
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