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
		explicit SensorMenager() = default;
		SensorMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iConfigMenager* configLoader, interface::iMessageQueue* messageQueue);
		virtual ~SensorMenager();

		utils::ErrorCode run();
		utils::ErrorCode setStatus(utils::Status status);

		utils::ErrorCode registerSensor(interface::iSensorService* sensorService);
		utils::ErrorCode pushNotPreparedMessage(uint8_t id, int message);
		utils::ErrorCode runSensor();
	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		interface::iMessageQueue* messageQueue;
		interface::iConfigMenager* configLoader;

		std::vector<interface::iSensorService*> sensorsWantToBeAlive;

		void deleteSensors();
	};
}