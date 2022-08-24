#pragma once

#include "../utils/ErrorCode.hpp"
#include "../utils/Status.hpp"

namespace interface
{
	class iSensorService
	{
	public:
		iSensorService(){
			this->status = utils::Status::CREATE;
		};
		virtual ~iSensorService() {};
		virtual utils::ErrorCode setStatus(utils::Status status) = 0;
		virtual utils::Status getStatus()
		{
			return this->status;
		}
		virtual utils::ErrorCode run() = 0;

	protected:
		utils::Status status;
	};
};
