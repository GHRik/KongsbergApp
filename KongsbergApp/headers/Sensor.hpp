#pragma once


#include "../interfaces/iSensorMenager.hpp"
#include <thread>

namespace sensorLayer
{
	class Sensor : public interface::iSensorService
	{
	public:
		Sensor( interface::iSensorMenager* sensorMenager, int id, int freq);
		virtual  ~Sensor();

		utils::ErrorCode setStatus(utils::Status status);
		utils::ErrorCode run();
	private:
		interface::iSensorMenager* sensorMenager;
		int id;
		int freq;

		std::thread thread;
	};
}