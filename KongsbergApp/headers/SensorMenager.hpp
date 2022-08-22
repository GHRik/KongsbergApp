#pragma once

#include "../interfaces/iSensorMenager.hpp"
#include "../interfaces/iMessageQueue.hpp"
#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../interfaces/iConfigMenager.hpp"

namespace common
{
	class SensorMenager : public interface::iSensorMenager, public interface::iLifeCycleService
	{
	public:
		SensorMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iConfigMenager* configMenager, interface::iMessageQueue* messageQueue);
		~SensorMenager();

		utils::ErrorCode run();
		utils::ErrorCode setStatus(utils::Status status);

		utils::ErrorCode registerSensor(iSensorMenager* sensorMenager);
		utils::ErrorCode pushNotPreparedMessage(uint8_t id, int message);
		utils::ErrorCode runSensor();
	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		interface::iMessageQueue* messageQueue;
		interface::iConfigMenager* configMenager;
		utils::Status status;
	};
}