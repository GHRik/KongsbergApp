/**
* @File MessageQueue.hpp
* @brief: have only queue(cyclic buffor) inside the class, nothing special
*
* @Owner Damian Panasiuk
*/

#pragma once

#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iMessageQueue.hpp"
#include "../interfaces/iLogger.hpp"
#include <vector>
#include "../interfaces/iConfigMenager.hpp"
#include "../utils/config.hpp"

namespace common
{
	class MessageQueue : public interface::iMessageQueue
	{
	public:
		explicit MessageQueue();
		virtual ~MessageQueue() = default;

		/**
		* On this function sensors can push on cyclic buffer.
		* @param: bufor id, sensor data
		**/
		utils::ErrorCode pushQueue(uint8_t id, int message) override;

		/**
		* On this function listeners can get data from
		* cyclic buffer.
		* @param: bufor id
		* @return data from front cyclic buffor[buffor id]
		**/
		int popQueue(uint8_t id) override;

		void stop();

		
	};
}