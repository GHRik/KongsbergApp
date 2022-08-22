#pragma once

#include "../interfaces/iListenerService.hpp"
#include "../interfaces/iListenerMenager.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <memory>

namespace listenerLayer
{
	class Listener : public interface::iListenerService
	{
	public:
		Listener(interface::iListenerMenager* listenerMenager, std::string name, int maxValue, int minValue, int frequency);
		virtual  ~Listener();
		utils::ErrorCode run();
		utils::ErrorCode setStatus(utils::Status status);
	private:
		interface::iListenerMenager* ListenerMenager;
		utils::Status status;

		std::string name;
		int maxValue;
		int minValue;
		int frequency;
		bool semaphore;

		std::thread thread;
	};
}
