#pragma once

#include "../utils/ErrorCode.hpp"
#include "../utils/Status.hpp"

namespace interface
{
	class iLifeCycleService
	{
	public:
		iLifeCycleService(){};
		virtual ~iLifeCycleService(){};
		virtual utils::ErrorCode setStatus(utils::Status status)
		{
			this->status = status;
			return utils::ErrorCode::OK;
		}
		virtual utils::Status getStatus()
		{
			return this->status;
		}
		virtual utils::ErrorCode run() = 0;

	protected:
		utils::Status status;
	};
};