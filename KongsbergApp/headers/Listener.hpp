#pragma once

#include "../interfaces/iListenerService.hpp"
#include "../interfaces/iListenerMenager.hpp"
#include "../utils/config.hpp"
#include <thread>
#include <chrono>

namespace listenerLayer
{
	class Listener : public interface::iListenerService
	{
	public:
		explicit Listener() = default;
		Listener(interface::iListenerMenager* listenerMenager, int id, std::string name, int maxValue, int minValue, int frequency);
		virtual  ~Listener() = default;
		utils::ErrorCode run();
		utils::ErrorCode setStatus(utils::Status status);
	private:
		interface::iListenerMenager* ListenerMenager;

		std::string name;
		int maxValue;
		int minValue;
		int frequency;
		int id;

		std::thread thread;

		void wrappAndLog(int message);
	};
}
