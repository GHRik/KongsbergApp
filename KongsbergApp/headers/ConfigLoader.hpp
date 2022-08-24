#pragma once

#include "../interfaces/iConfigMenager.hpp"
#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../utils/config.hpp"
#include "../include/nlohmann/json.hpp"
#include <fstream>
#include <sstream>


namespace common
{
	class ConfigLoader : public interface::iConfigMenager, public interface::iLifeCycleService
	{
	public:
		ConfigLoader(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager);
		virtual ~ConfigLoader();
		const uint8_t getNumberAliveSensors() const;
		const std::vector<int> getAliveSensorsID() const;
		const std::vector<int> getAliveSensorsMin() const;
		const std::vector<int> getAliveSensorsMax() const;
		const std::vector<int> getAliveSensorsFreq() const;
		const std::vector<std::string> getAliveSensorsName() const;

		utils::ErrorCode setStatus(utils::Status status);
		utils::ErrorCode run();
	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;

		std::vector<int> aliveSensorsID;
		std::vector<int> aliveSensorsMin;
		std::vector<int> aliveSensorsMax;
		std::vector<int> aliveSensorsFreq;
		std::vector<std::string> aliveSensorsName;
		uint8_t aliveSensorsAmount;

		void translateConfig(std::vector<std::vector<std::string>> &configToTranslate);
		bool isConfigValid( const std::vector<std::vector<std::string>> &configToValid) const;
		void clearSensorsResource();
		bool isIDUnique(const std::vector<std::vector<std::string>> &config) const;
		bool isIDFromUint8( const std::vector<std::vector<std::string>> &config) const;
		bool isNumberInNecesarryField( const std::vector<std::vector<std::string>> &config) const;
		bool is_number(const std::string& s) const;

	};
}