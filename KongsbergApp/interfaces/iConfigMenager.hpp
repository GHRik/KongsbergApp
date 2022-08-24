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
		const virtual uint8_t getNumberAliveSensors() const = 0;
		const virtual std::vector<int> getAliveSensorsID() const = 0;
		const virtual std::vector<int> getAliveSensorsMin() const = 0;
		const virtual std::vector<int> getAliveSensorsMax() const = 0;
		const virtual std::vector<int> getAliveSensorsFreq() const = 0;
		const virtual std::vector<std::string> getAliveSensorsName() const = 0;
	};
};
