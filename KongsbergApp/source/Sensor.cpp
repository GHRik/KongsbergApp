#include "../headers/Sensor.hpp"


sensorLayer::Sensor::Sensor(interface::iSensorMenager* sensorMenager, int id, int freq, int minRange, int maxRange)
	: sensorMenager(sensorMenager), id(id), freq(freq), minRange(minRange), maxRange(maxRange)
{
	sensorMenager->registerSensor(this);
}
utils::ErrorCode sensorLayer::Sensor::run()
{
	std::chrono::seconds timespan(1/this->freq);
	std::random_device rd;
	int startRange = this->minRange;
	int endRange = this->maxRange;
	std::uniform_int_distribution<> distr(startRange, endRange);
	this->status = utils::Status::WORK;
	while (this->status == utils::Status::WORK)
	{
		std::mt19937 gen(rd());
		this->sensorMenager->pushNotPreparedMessage(this->id, distr(gen));
		std::this_thread::sleep_for(timespan);
	}
	return utils::ErrorCode::OK;
}

utils::ErrorCode sensorLayer::Sensor::setStatus(utils::Status status)
{
	switch (status)
	{
	case utils::Status::INIT:
		this->status = utils::Status::INIT;
		break;
	case utils::Status::START:
		this->status = utils::Status::START;
		break;
	case utils::Status::WORK:
		this->thread = std::thread(&sensorLayer::Sensor::run, this);
		this->status = utils::Status::WORK;
		break;
	case utils::Status::STOP:
		if (this->status == utils::Status::WORK)
		{
			this->status = utils::Status::STOP;
			this->thread.join();
		}
		this->status = utils::Status::STOP;

		break;

	}
	return utils::ErrorCode::OK;
}