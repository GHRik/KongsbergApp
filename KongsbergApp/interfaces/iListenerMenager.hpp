#pragma once

#include <string>
#include "../utils/ErrorCode.hpp"

namespace interface
{
	class iListenerMenager
	{
	public:
		iListenerMenager(){};
		virtual ~iListenerMenager(){};
		virtual utils::ErrorCode registerListener(iListenerMenager* listenerMenager) = 0;
		virtual std::string popNotPreparedMessage() = 0;
		virtual utils::ErrorCode pushPreparedMessage(std::string) = 0;
		virtual utils::ErrorCode runListener() = 0;

	};
}