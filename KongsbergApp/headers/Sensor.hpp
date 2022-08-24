/**
* @File Sensor.hpp
* @brief:  responsible for symulate data and push this data on messageQueue[sensorID]
*
* @Owner Damian Panasiuk
*/

#pragma once

#include "../interfaces/iSensorMenager.hpp"
#include <thread>
#include <random>

namespace sensorLayer
{
	class Sensor : public interface::iSensorService
	{
	public:
		Sensor() = delete;
		Sensor( interface::iSensorMenager* sensorMenager, int id, int freq, int minRange, int maxRange);
		virtual  ~Sensor() = default;

		/**
		* By this function  SensorMenager can easy
		* menage Sensor state.
		**/
		utils::ErrorCode setStatus(utils::Status status) override;

		/**
		* Routine have own thread. On this routine
		* Sensor create random data from minValue to maxValue.
		* This data is going to be pushed on cyclicBuffer.
		**/
		utils::ErrorCode run() override;
	private:
		interface::iSensorMenager* sensorMenager;
		const int id;
		const int freq;
		const int minRange;
		const int maxRange;

		std::thread thread;
	};
}