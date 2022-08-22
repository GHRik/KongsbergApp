#pragma once

#include <string>
#include "../utils/ErrorCode.hpp"
#include "iLogger.hpp"

namespace interface
{
	class iListenerMenager
	{
	public:
		iListenerMenager(){};
		virtual ~iListenerMenager(){};
		virtual utils::ErrorCode registerListener(iListenerService* listenerService) = 0;
		virtual int popNotPreparedMessage(uint8_t id) = 0;
		virtual utils::ErrorCode pushPreparedMessage(uint8_t id, int message) = 0;
		virtual utils::ErrorCode runListener() = 0;

		iLogger* logger;
	};
}