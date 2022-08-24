#pragma once

#include <vector>
#include "../utils/ErrorCode.hpp"
#include "boost/circular_buffer.hpp"

namespace interface
{
	class iMessageQueue
	{
	public:
		iMessageQueue(){};
		virtual ~iMessageQueue(){};
		virtual utils::ErrorCode pushQueue(uint8_t id, int message ) = 0;
		virtual int popQueue( uint8_t id) = 0;

		std::vector<boost::circular_buffer<int>> queue;
	};
};