#include "../headers/Sensor.hpp"


sensorLayer::Sensor::Sensor(interface::iSensorMenager* sensorMenager, int id, int freq)
{
	this->sensorMenager = sensorMenager;
	this->id = id;
	this->freq = freq;
	sensorMenager->registerSensor(this);


}

sensorLayer::Sensor::~Sensor()
{

}

utils::ErrorCode sensorLayer::Sensor::run()
{
	std::chrono::seconds timespan(this->freq);
	srand(1);
	int random = 1000;
	this->status = utils::Status::WORK;
	while (this->status == utils::Status::WORK)
	{
		this->sensorMenager->pushNotPreparedMessage(this->id, this->id);
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