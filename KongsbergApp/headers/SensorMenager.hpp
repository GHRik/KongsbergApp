#pragma once

#include "../interfaces/iSensorMenager.hpp"
#include "../interfaces/iMessageQueue.hpp"
#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"

namespace common
{
	class SensorMenager : public interface::iSensorMenager, public interface::iLifeCycleService
	{
	public:
		SensorMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iMessageQueue* messageQueue);
		~SensorMenager();

		utils::ErrorCode setStatus(utils::Status status);
		utils::Status getStatus();
		utils::ErrorCode run();

		utils::ErrorCode registerListener(iSensorMenager* sensorMenager);
		utils::ErrorCode pushNotPreparedMessage(std::string message);
		utils::ErrorCode runSensor();
	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		interface::iMessageQueue* messageQueue;
		utils::Status status;
	};
}