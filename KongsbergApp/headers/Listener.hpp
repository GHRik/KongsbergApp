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
		Listener() = delete;
		Listener(interface::iListenerMenager* listenerMenager, int id, const std::string &name, int maxValue, int minValue, int frequency);
		virtual  ~Listener() = default;
		utils::ErrorCode run() override;
		utils::ErrorCode setStatus(utils::Status status) override;
	private:
		interface::iListenerMenager* ListenerMenager;

		const std::string name;
		const int maxValue;
		const int minValue;
		const int frequency;
		const int id;

		std::thread thread;

		void wrappAndLog(int message);
	};
}
