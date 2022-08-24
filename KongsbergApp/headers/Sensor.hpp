#pragma once


#include "../interfaces/iSensorMenager.hpp"
#include <thread>
#include <random>

namespace sensorLayer
{
	class Sensor : public interface::iSensorService
	{
	public:
		explicit Sensor() = default;
		Sensor( interface::iSensorMenager* sensorMenager, int id, int freq, int minRange, int maxRange);
		virtual  ~Sensor() = default;

		utils::ErrorCode setStatus(utils::Status status);
		utils::ErrorCode run();
	private:
		interface::iSensorMenager* sensorMenager;
		const int id;
		const int freq;
		const int minRange;
		const int maxRange;

		std::thread thread;
	};
}