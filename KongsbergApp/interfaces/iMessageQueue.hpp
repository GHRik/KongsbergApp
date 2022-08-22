#pragma once

#include <vector>
#include "../utils/ErrorCode.hpp"
#include "../utils/queue_id.hpp"

namespace interface
{
	class iMessageQueue
	{
	public:
		iMessageQueue(){};
		virtual ~iMessageQueue(){};
		virtual utils::ErrorCode pushQueue(uint8_t id, int message ) = 0;
		virtual int popQueue( uint8_t id, int message) = 0;

		std::vector<std::vector<int>> queue;
	};
};