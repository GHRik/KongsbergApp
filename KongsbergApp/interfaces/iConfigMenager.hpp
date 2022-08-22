#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../utils/ErrorCode.hpp"

namespace interface
{
	class iConfigMenager
	{
	public:
		iConfigMenager(){};
		virtual ~iConfigMenager(){};
		virtual uint8_t getNumberAliveSensors() = 0;
		virtual std::vector<int> getAliveSensorsID() = 0;
		virtual std::vector<int> getAliveSensorsMin() = 0;
		virtual std::vector<int> getAliveSensorsMax() = 0;
		virtual std::vector<int> getAliveSensorsFreq() = 0;
		virtual std::vector<std::string> getAliveSensorsName() = 0;
	};
};
