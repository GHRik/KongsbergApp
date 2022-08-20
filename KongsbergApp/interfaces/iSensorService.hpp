#pragma once

#include "../interfaces/iSensorMenager.hpp"
#include "../utils/ErrorCode.hpp"
#include "../utils/Status.hpp"

namespace interface
{
	class iSensorService
	{
	public:
		iSensorService(){};
		virtual ~iSensorService() {};
		virtual utils::ErrorCode setStatus(utils::Status status) = 0;
		virtual utils::Status getStatus() = 0;
		virtual utils::ErrorCode run() = 0;
	};
};
