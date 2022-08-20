#pragma once

#include <string>
#include "../utils/ErrorCode.hpp"

namespace interface
{
	class iMessageWrapper
	{
	public:
		iMessageWrapper(){};
		virtual ~iMessageWrapper(){};
		virtual std::string wrappAndLogMessage( std::string message ) = 0;
	};
};
