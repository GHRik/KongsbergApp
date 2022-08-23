#pragma once


#include "../interfaces/iSensorMenager.hpp"
#include <thread>
#include <random>

namespace sensorLayer
{
	class Sensor : public interface::iSensorService
	{
	public:
		Sensor( interface::iSensorMenager* sensorMenager, int id, int freq, int minRange, int maxRange);
		virtual  ~Sensor();

		utils::ErrorCode setStatus(utils::Status status);
		utils::ErrorCode run();
	private:
		interface::iSensorMenager* sensorMenager;
		int id;
		int freq;
		int minRange;
		int maxRange;

		std::thread thread;
	};
}