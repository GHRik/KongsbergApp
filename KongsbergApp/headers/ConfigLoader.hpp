#pragma once

#include "../interfaces/iConfigMenager.hpp"
#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../interfaces/iStreamMenager.hpp"


namespace common
{
	class ConfigLoader : public interface::iConfigMenager, public interface::iLifeCycleService
	{
	public:
		ConfigLoader(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager, interface::iStreamMenager* streamMenager);
		virtual ~ConfigLoader();
		uint8_t getNumberAliveSensors();
		std::vector<int> getAliveSensorsID();
		std::vector<int> getAliveSensorsMin();
		std::vector<int> getAliveSensorsMax();
		std::vector<int> getAliveSensorsFreq();

		utils::ErrorCode setStatus(utils::Status status);
		utils::Status getStatus();
		utils::ErrorCode run();
	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		interface::iStreamMenager* streamMenager;
		utils::Status status;

	};
}