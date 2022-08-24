/**
* @File Listener.hpp
* @brief: responsible for take data from messageQueue, corectly wrapp this data and log.
*
* @Owner Damian Panasiuk
*/

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

		/**
		* Is routine. Run in separated thread.
		* On this routine listener get data from
		* cyclic buffer and wrapp it. Wrapped data
		* is logged by ListenerMenager and print.
		**/
		utils::ErrorCode run() override;

		/**
		* ListenerMenager module can menage status with this function.
		**/
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
