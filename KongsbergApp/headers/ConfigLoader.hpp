#pragma once

#include "../interfaces/iConfigMenager.hpp"
#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../utils/config.hpp"
#include <fstream>
#include "../include/nlohmann/json.hpp"
#include <unordered_map>
#include <sstream>


namespace common
{
	class ConfigLoader : public interface::iConfigMenager, public interface::iLifeCycleService
	{
	public:
		ConfigLoader(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager);
		virtual ~ConfigLoader();
		uint8_t getNumberAliveSensors();
		std::vector<int> getAliveSensorsID();
		std::vector<int> getAliveSensorsMin();
		std::vector<int> getAliveSensorsMax();
		std::vector<int> getAliveSensorsFreq();

		utils::ErrorCode setStatus(utils::Status status);
		utils::ErrorCode run();
	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		utils::Status status;
		std::string content;

		std::vector<int> aliveSensorsID;
		std::vector<int> aliveSensorsMin;
		std::vector<int> aliveSensorsMax;
		std::vector<int> aliveSensorsFreq;
		std::vector<std::string> aliveSensorsName;
		uint8_t aliveSensorsAmount;

		void translateConfig(std::vector<std::vector<std::string>> configToTranslate);
		bool isConfigValid(std::vector<std::vector<std::string>> configToValid);
		bool is_number(const std::string& s);

	};
}