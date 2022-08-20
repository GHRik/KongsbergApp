#include "../headers/Sensor.hpp"


sensorLayer::Sensor::Sensor(interface::iSensorMenager* sensorMenager)
{

}

sensorLayer::Sensor::~Sensor()
{

}

utils::ErrorCode sensorLayer::Sensor::setStatus(utils::Status)
{
	return utils::ErrorCode::NOK;
}

utils::Status sensorLayer::Sensor::getStatus()
{
	return utils::Status::START;
}

utils::ErrorCode sensorLayer::Sensor::run()
{
	return utils::ErrorCode::NOK;
}