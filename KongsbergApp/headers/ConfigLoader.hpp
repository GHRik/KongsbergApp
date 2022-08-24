/**
* @File ConfigLoader.hpp
* @brief: responsible for parse and validate config from Config.json
* 
* @Owner Damian Panasiuk
*/

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
		ConfigLoader() = delete;
		ConfigLoader(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager);
		virtual ~ConfigLoader() = default;
		/**
		* After parse json this function will return a number of sensors
		* which have "alive: true" in config.json
		* 
		* @return amount of sensors from config.json
		**/
		const uint8_t getNumberAliveSensors() const override;

		/**
		* After parse json this function will return a vector
		* of sensors id. In vector are only alive sensors.
		*
		* @return vector of ids from config.json
		**/
		const std::vector<int> getAliveSensorsID() const override;

		/**
		* After parse json this function will return a vector
		* of sensors min value. In vector are only alive sensors.
		*
		* @return vector of min value from config.json
		**/
		const std::vector<int> getAliveSensorsMin() const override;

		/**
		* After parse json this function will return a vector
		* of sensors max value. In vector are only alive sensors.
		*
		* @return vector of max value from config.json
		**/
		const std::vector<int> getAliveSensorsMax() const override;

		/**
		* After parse json this function will return a vector
		* of sensors frequency in Hz. In vector are only alive sensors.
		*
		* @return vector of frequency in Hz from config.json
		**/
		const std::vector<int> getAliveSensorsFreq() const override;

		/**
		* After parse json this function will return a vector
		* of sensors name. In vector are only alive sensors.
		*
		* @return vector of name from config.json
		**/
		const std::vector<std::string> getAliveSensorsName() const override;

		/**
		* LifeCycle module can menage status with this function.
		*
		**/
		utils::ErrorCode setStatus(utils::Status status) override;

		/**
		* Routine of configLoader. ConfigLoader routine will
		* run in main thread.
		*
		**/
		utils::ErrorCode run() override;
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