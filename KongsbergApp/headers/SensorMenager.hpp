/**
* @File SensorMenager.hpp
* @brief:  responsible for create and menage sensors
*
* @Owner Damian Panasiuk
*/

#pragma once

#include "../interfaces/iSensorMenager.hpp"
#include "../interfaces/iMessageQueue.hpp"
#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../interfaces/iConfigMenager.hpp"
#include "../interfaces/iSensorService.hpp"
#include "../headers/Sensor.hpp"

namespace common
{
	class SensorMenager : public interface::iSensorMenager, public interface::iLifeCycleService
	{
	public:
		SensorMenager() = delete;
		SensorMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iConfigMenager* configLoader, interface::iMessageQueue* messageQueue);
		virtual ~SensorMenager();

		utils::ErrorCode run() override;

		/**
		* LifeCycle module can menage status with this function.
		**/
		utils::ErrorCode setStatus(utils::Status status) override;

		/**
		* On this function Sensors can registry to SensorMenager.
		* Registry mean add to vector. With pointers on Sensors
		* SensorMenager can easly menage Sensors like destroy, create etc.
		**/
		utils::ErrorCode registerSensor(interface::iSensorService* sensorService) override;

		/**
		* On this function Sensors by SensorMenager send data on
		* cyclicBuffor.
		* @param: bufor id, message with data
		**/
		utils::ErrorCode pushNotPreparedMessage(uint8_t id, int message) override;

	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		interface::iMessageQueue* messageQueue;
		interface::iConfigMenager* configLoader;

		std::vector<interface::iSensorService*> sensorsWantToBeAlive;

		void deleteSensors();
	};
}