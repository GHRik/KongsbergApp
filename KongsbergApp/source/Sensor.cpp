#include "../headers/Sensor.hpp"


sensorLayer::Sensor::Sensor(interface::iSensorMenager* sensorMenager)
{

}

sensorLayer::Sensor::~Sensor()
{

}

utils::ErrorCode sensorLayer::Sensor::run()
{
	return utils::ErrorCode::NOK;
}