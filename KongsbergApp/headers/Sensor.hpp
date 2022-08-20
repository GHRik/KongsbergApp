#pragma once


#include "../interfaces/iSensorService.hpp"

namespace sensorLayer
{
	class Sensor : public interface::iSensorService
	{
	public:
		Sensor( interface::iSensorMenager* sensorMenager);
		virtual  ~Sensor();
		utils::ErrorCode setStatus(utils::Status status);
		utils::Status getStatus();
		utils::ErrorCode run();
	private:
		interface::iSensorMenager* sensorMenager;
		utils::Status status;
	};
}