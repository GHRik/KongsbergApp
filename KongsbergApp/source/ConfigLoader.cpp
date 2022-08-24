#include "../headers/ConfigLoader.hpp"

common::ConfigLoader::ConfigLoader(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager)
	: logger(logger), lifeCycleMenager(lifeCycleMenager), aliveSensorsAmount(0)
{
	this->lifeCycleMenager->registry(this);
	status = utils::Status::CREATE;
}

common::ConfigLoader::~ConfigLoader()
{
}

const uint8_t common::ConfigLoader::getNumberAliveSensors() const
{
	return aliveSensorsAmount;
}

const std::vector<int> common::ConfigLoader::getAliveSensorsID() const
{
	return aliveSensorsID;
}

const std::vector<int> common::ConfigLoader::getAliveSensorsMin() const
{
	return aliveSensorsMin;
}

const std::vector<int> common::ConfigLoader::getAliveSensorsMax() const
{
	return aliveSensorsMax;
}

const std::vector<int> common::ConfigLoader::getAliveSensorsFreq() const
{
	return aliveSensorsFreq;
}

const std::vector<std::string> common::ConfigLoader::getAliveSensorsName() const
{
	return aliveSensorsName;
}


utils::ErrorCode common::ConfigLoader::run()
{
	std::stringstream sensorContent_tmp;
	std::ifstream f(utils::CONFIG_FILE);
	std::stringstream buffer;
	buffer << f.rdbuf();
	f.close();
	f.open(utils::CONFIG_FILE);

	if (nlohmann::json::accept(buffer) == false)
	{
		logger->logError("ERROR JSON: ", "Json file is not valid");
		return utils::ErrorCode::NOK;
	}

	nlohmann::json data = nlohmann::json::parse(f);
	f.close();

	for (auto it = data.begin(); it != data.end(); ++it)
	{
		if (!data.contains(utils::JSON_HEADER))
		{
			logger->logError("ERROR JSON: ", "key: \"" + utils::JSON_HEADER + "\" could not be find");
			return utils::ErrorCode::NOK;
		}
	}

	for (auto it = data.begin(); it != data.end(); ++it)
	{
		if (it.key() == utils::JSON_HEADER)
		{
			sensorContent_tmp << it.value();
			break;
		}
	}
	std::string sensorContent;
	sensorContent_tmp >> sensorContent;


	int counterAlive = 0;
	std::vector<std::vector<std::string>> sensorInfo;

	data = nlohmann::json::parse(sensorContent);
	std::vector<std::string> configElem(utils::NUMBER_OF_CONFIG_ELEM);
	
	uint8_t counter = 0;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		counter++;

		if (!it.value().contains(utils::JSON_ID) || !it.value().contains(utils::JSON_NAME) ||
			!it.value().contains(utils::JSON_MAX) || !it.value().contains(utils::JSON_MIN) ||
			!it.value().contains(utils::JSON_ALIVE) || !it.value().contains(utils::JSON_FREQ) )
		{
			std::string result = "Unable to find one of necessary field, on position "+ std::to_string(counter);
			logger->logError("ERROR JSON: ", result);
			return utils::ErrorCode::NOK;
		}

		sensorContent_tmp.clear();
		if (it.value()[utils::JSON_ALIVE] == false || it.value()[utils::JSON_ALIVE] == 0)
		{
			continue;
		}

		sensorContent_tmp << it.value()[utils::JSON_ID] << ' ' << it.value()[utils::JSON_NAME]
			<< ' ' << it.value()[utils::JSON_MAX] << ' ' << it.value()[utils::JSON_MIN]
			<< ' ' << it.value()[utils::JSON_ALIVE] << ' ' << it.value()[utils::JSON_FREQ];
		std::string id, name, maxVal, minVal, alive, freq;
		sensorContent_tmp >> id >> name >> maxVal >> minVal >> alive >> freq;

		if (std::stoi(maxVal) < std::stoi(minVal))
		{
			logger->logError("JSON ERROR: ", maxVal + " < " + minVal);
			return utils::ErrorCode::NOK;
		}

		configElem.insert(configElem.begin() + utils::ID_PLACE, id);
		configElem.insert(configElem.begin() + utils::NAME_PLACE, name);
		configElem.insert(configElem.begin() + utils::MIN_PLACE, minVal);
		configElem.insert(configElem.begin() + utils::MAX_PLACE, maxVal);
		configElem.insert(configElem.begin() + utils::ALIVE_PLACE, alive);
		configElem.insert(configElem.begin() + utils::FREQ_PLACE, freq);
		
		sensorInfo.push_back(configElem);
	}
	if (isConfigValid(sensorInfo) == false)
	{
		logger->logError("ERROR JSON: ","JSON config not valid");
		return utils::ErrorCode::NOK;
	}
		
	translateConfig(sensorInfo);
	aliveSensorsAmount = static_cast<uint8_t>(sensorInfo.size());

	return utils::ErrorCode::OK;
}

bool common::ConfigLoader::isConfigValid(const std::vector<std::vector<std::string>> &configToValid) const
{
		
	if (isIDFromUint8(configToValid) == false || isIDUnique(configToValid) == false || isNumberInNecesarryField(configToValid) == false)
	{
		return false;
	}
				
	return true;
}

bool common::ConfigLoader::isIDUnique(const std::vector<std::vector<std::string>> &config) const
{
	for (int i = 0; i < config.size(); ++i)
	{
		for (int j = 0; j < config.size(); ++j)
		{
			if (config.at(i).at(utils::ID_PLACE) == config.at(j).at(utils::ID_PLACE) && i != j)
			{
				logger->logError("ERROR JSON: ", config.at(i).at(utils::ID_PLACE) + " ID is duplicated");
				return false;
			}
		}
	}
	return true;
}

bool common::ConfigLoader::isIDFromUint8(const std::vector<std::vector<std::string>> &config) const
{
	for (int i = 0; i < config.size(); ++i)
	{
		if (std::stoi(config.at(i).at(utils::ID_PLACE)) >= 255 || std::stoi(config.at(i).at(utils::ID_PLACE)) < 0)
		{
			logger->logError("ERROR JSON: ", config.at(i).at(utils::ID_PLACE) + " ID is >= 255 or < 0");
			return false;
		}
	}
	return true;
}

bool common::ConfigLoader::isNumberInNecesarryField(const std::vector<std::vector<std::string>> &config) const
{
	for (int i = 0; i < config.size(); ++i)
	{
		if (is_number(config.at(i).at(utils::ID_PLACE)) == false)
		{
			logger->logError("ERROR JSON: ", config.at(i).at(utils::ID_PLACE) + " is not number");
			return false;
		}
		if (is_number(config.at(i).at(utils::MIN_PLACE)) == false)
		{
			logger->logError("ERROR JSON: ", config.at(i).at(utils::MIN_PLACE) + " is not number");
			return false;
		}
		if (is_number(config.at(i).at(utils::MAX_PLACE)) == false)
		{
			logger->logError("ERROR JSON: ", config.at(i).at(utils::MAX_PLACE) + " is not number");
			return false;
		}
		if (is_number(config.at(i).at(utils::FREQ_PLACE)) == false)
		{
			logger->logError("ERROR JSON: ", config.at(i).at(utils::FREQ_PLACE) + " is not number");
			return false;
		}
	}
	return true;
}


bool common::ConfigLoader::is_number(const std::string& s) const
{
	std::string::const_iterator it = s.begin();
	if (it == s.begin() && * s.begin() == '-')
	{
		++it;
	}
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

void common::ConfigLoader::translateConfig(std::vector<std::vector<std::string>> &configToTranslate)
{
	for (int i = 0; i < configToTranslate.size(); ++i)
	{
		aliveSensorsID.push_back(std::stoi(configToTranslate.at(i).at(utils::ID_PLACE)));
		aliveSensorsMin.push_back(std::stoi(configToTranslate.at(i).at(utils::MIN_PLACE)));
		aliveSensorsMax.push_back(std::stoi(configToTranslate.at(i).at(utils::MAX_PLACE)));
		aliveSensorsFreq.push_back(std::stoi(configToTranslate.at(i).at(utils::FREQ_PLACE)));
		aliveSensorsName.push_back(configToTranslate.at(i).at(utils::NAME_PLACE));
	}
}

utils::ErrorCode common::ConfigLoader::setStatus(utils::Status status)
{
	switch (status)
	{
	case utils::Status::INIT:
		this->status = utils::Status::INIT;
		return this->run();
	case utils::Status::START:
		this->status = utils::Status::START;
		break;
	case utils::Status::WORK:
		this->status = utils::Status::WORK;
		break;
	case utils::Status::STOP:
		this->status = utils::Status::STOP;
		clearSensorsResource();
		break;

	}
	return utils::ErrorCode::OK;
}

void common::ConfigLoader::clearSensorsResource()
{
	this->aliveSensorsAmount = 0;
	this->aliveSensorsID.clear();
	this->aliveSensorsMin.clear();
	this->aliveSensorsMax.clear();
	this->aliveSensorsFreq.clear();
	this->aliveSensorsName.clear();
}
