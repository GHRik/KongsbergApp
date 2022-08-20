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
		virtual utils::ErrorCode setStatus(utils::Status status) = 0;
		virtual utils::Status getStatus() = 0;
		virtual utils::ErrorCode run() = 0;
	};
};