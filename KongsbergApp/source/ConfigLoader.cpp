#include "../headers/ConfigLoader.hpp"

common::ConfigLoader::ConfigLoader(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager)
{
	this->logger = logger;
	this->lifeCycleMenager = lifeCycleMenager;
	this->lifeCycleMenager->registry(this);
}

common::ConfigLoader::~ConfigLoader()
{
}

uint8_t common::ConfigLoader::getNumberAliveSensors()
{
	return aliveSensorsAmount;
}

std::vector<int> common::ConfigLoader::getAliveSensorsID()
{
	return aliveSensorsID;
}

std::vector<int> common::ConfigLoader::getAliveSensorsMin()
{
	return aliveSensorsMin;
}

std::vector<int> common::ConfigLoader::getAliveSensorsMax()
{
	return aliveSensorsMax;
}

std::vector<int> common::ConfigLoader::getAliveSensorsFreq()
{
	return aliveSensorsFreq;
}

std::vector<std::string> common::ConfigLoader::getAliveSensorsName()
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
	
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		std::string id, name, maxVal, minVal, alive, freq ;

		sensorContent_tmp.clear();
		sensorContent_tmp << it.value()[utils::JSON_ID] << ' ' << it.value()[utils::JSON_NAME]
			<< ' ' << it.value()[utils::JSON_MAX] << ' ' << it.value()[utils::JSON_MIN]
			<< ' ' << it.value()[utils::JSON_ALIVE] << ' ' << it.value()[utils::JSON_FREQ];
		sensorContent_tmp >> id >> name >> maxVal >> minVal >> alive >> freq;

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
	aliveSensorsAmount = sensorInfo.size();

	return utils::ErrorCode::OK;
}

bool common::ConfigLoader::isConfigValid(std::vector<std::vector<std::string>> configToValid)
{
	for (int i = 0; i < configToValid.size(); ++i)
	{
		if (is_number(configToValid.at(i).at(utils::ID_PLACE)) == false)
		{
			logger->logError("ERROR JSON: ", configToValid.at(i).at(utils::ID_PLACE) + " is not number");
			return false;
		}
		if (is_number(configToValid.at(i).at(utils::MIN_PLACE)) == false)
		{
			logger->logError("ERROR JSON: ", configToValid.at(i).at(utils::MIN_PLACE) + " is not number");
			return false;
		}
		if (is_number(configToValid.at(i).at(utils::MAX_PLACE)) == false)
		{
			logger->logError("ERROR JSON: ", configToValid.at(i).at(utils::MAX_PLACE) + " is not number");
			return false;
		}
		if (is_number(configToValid.at(i).at(utils::FREQ_PLACE)) == false)
		{
			logger->logError("ERROR JSON: ", configToValid.at(i).at(utils::FREQ_PLACE) + " is not number");
			return false;
		}
	}	
				
	return true;
}

bool common::ConfigLoader::is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	if (it == s.begin() && * s.begin() == '-')
	{
		++it;
	}
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

void common::ConfigLoader::translateConfig(std::vector<std::vector<std::string>> configToTranslate)
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
		this->run();
		break;
	case utils::Status::START:
		this->status = utils::Status::START;
		break;
	case utils::Status::WORK:
		this->status = utils::Status::WORK;
		break;
	case utils::Status::STOP:
		this->status = utils::Status::STOP;
		break;

	}
	return utils::ErrorCode::OK;
}
