#pragma once

#include <string>
#include "../utils/ErrorCode.hpp"
#include "../utils/queue_id.hpp"

namespace interface
{
	class iMessageQueue
	{
	public:
		iMessageQueue(){};
		virtual ~iMessageQueue(){};
		virtual utils::ErrorCode pushQueue(utils::queue_id id, std::string message ) = 0;
		virtual utils::ErrorCode popQueue( utils::queue_id id, std::string message) = 0;
	};
};