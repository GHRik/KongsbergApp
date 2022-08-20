#pragma once

#include <string>
#include "../utils/ErrorCode.hpp"

namespace interface
{
	class iMessageQeueu
	{
	public:
		iMessageQeueu(){};
		virtual ~iMessageQeueu(){};
		virtual utils::ErrorCode pushQueue( std::string message ) = 0;
		virtual utils::ErrorCode popQueue(std::string message) = 0;
	};
};