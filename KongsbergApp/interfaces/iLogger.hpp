#pragma once

#include <string>
#include "../utils/ErrorCode.hpp"

namespace interface
{
	class iLogger
	{
	public:
		iLogger(){};
		virtual ~iLogger(){};
		virtual utils::ErrorCode logError(std::string tag, std::string message) = 0;
		virtual utils::ErrorCode logWarn(std::string tag, std::string message) = 0;
		virtual utils::ErrorCode logInfo(std::string tag, std::string message) = 0;
	};
};
