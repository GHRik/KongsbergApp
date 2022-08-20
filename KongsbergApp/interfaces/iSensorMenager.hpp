#pragma once

#include <string>
#include "../utils/ErrorCode.hpp"

namespace interface
{
	class iSensorMenager
	{
	public:
		iSensorMenager(){};
		virtual ~iSensorMenager(){};
		virtual utils::ErrorCode registerListener(iSensorMenager* sensorMenager) = 0;
		virtual utils::ErrorCode pushNotPreparedMessage(std::string message) = 0;
		virtual utils::ErrorCode runSensor() = 0;

	};
};
