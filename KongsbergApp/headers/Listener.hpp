#pragma once

#include "../interfaces/iListenerService.hpp"
#include "../interfaces/iListenerMenager.hpp"
#include "../utils/config.hpp"
#include <thread>
#include <chrono>
#include <iostream>

namespace listenerLayer
{
	class Listener : public interface::iListenerService
	{
	public:
		Listener(interface::iListenerMenager* listenerMenager, int id, std::string name, int maxValue, int minValue, int frequency);
		virtual  ~Listener();
		utils::ErrorCode run();
		utils::ErrorCode setStatus(utils::Status status);
	private:
		interface::iListenerMenager* ListenerMenager;

		std::string name;
		int maxValue;
		int minValue;
		int frequency;
		int id;
		bool semaphore;

		std::thread thread;

		void wrappAndLog(int message);
	};
}
