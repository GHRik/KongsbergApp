#pragma once

#include <string>
#include "../utils/ErrorCode.hpp"
#include "iSensorService.hpp"

namespace interface
{
	class iSensorMenager
	{
	public:
		iSensorMenager(){};
		virtual ~iSensorMenager(){};
		virtual utils::ErrorCode registerSensor(iSensorService* sensorService) = 0;
		virtual utils::ErrorCode pushNotPreparedMessage(uint8_t id, int message) = 0;

	};
};
