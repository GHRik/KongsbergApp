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
		virtual utils::ErrorCode logError(const std::string &tag, const std::string &message) = 0;
		virtual utils::ErrorCode logInfo(const std::string &tag, const std::string &message) = 0;
	};
};
