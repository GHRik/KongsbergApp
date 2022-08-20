#pragma once

#include "../utils/ErrorCode.hpp"
#include "iLifeCycleService.hpp"

namespace interface
{
	class iLifeCycleMenager
	{
	public:
		iLifeCycleMenager(){};
		virtual ~iLifeCycleMenager(){};
		virtual utils::ErrorCode registry(iLifeCycleService* service) = 0;
		virtual utils::ErrorCode run() = 0;
		virtual utils::ErrorCode stop() = 0;

	};
};