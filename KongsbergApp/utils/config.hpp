#pragma once

#include <string>
#include <iostream>

namespace utils
{
	const std::string CONFIG_FILE = "SensorConfig.json";

	const std::string JSON_HEADER = "Sensors";
	const std::string JSON_ID = "ID";
	const std::string JSON_NAME = "Type";
	const std::string JSON_MIN = "MinValue";
	const std::string JSON_MAX = "MaxValue";
	const std::string JSON_ALIVE = "Alive";
	const std::string JSON_FREQ = "FrequencyHz";
	const std::uint8_t NUMBER_OF_CONFIG_ELEM = 6;

	constexpr std::uint8_t ID_PLACE = 0;
	constexpr std::uint8_t NAME_PLACE = 1;
	constexpr std::uint8_t MIN_PLACE = 2;
	constexpr std::uint8_t MAX_PLACE = 3;
	constexpr std::uint8_t ALIVE_PLACE = 4;
	constexpr std::uint8_t FREQ_PLACE = 5;

	const std::string PREFIX_MESSAGE = "$FIX";

	constexpr double alarmPercent = 0.1;
	constexpr double warnPercent = 0.15;

	constexpr uint16_t logSleepMilisec = 1000;

	constexpr uint8_t maxAmountOfSensors = 255;
	constexpr uint16_t cyclicBufferSize = 1000;

}
