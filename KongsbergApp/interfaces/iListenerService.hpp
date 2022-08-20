#pragma once

#include "../interfaces/iListenerMenager.hpp"
#include "../utils/ErrorCode.hpp"
#include "../utils/Status.hpp"

namespace interface
{
	class iListenerService
	{
	public:
		iListenerService(){};
		virtual ~iListenerService(){};
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
