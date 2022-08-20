#include "../headers/StreamMenager.hpp"


common::StreamMenager::StreamMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager)
{
	this->logger = logger;
	this->lifeCycleMenager = lifeCycleMenager;
	this->lifeCycleMenager->registry(this);
}

common::StreamMenager::~StreamMenager()
{
}

utils::ErrorCode common::StreamMenager::setStatus(utils::Status status)
{
	return utils::ErrorCode::NOK;
}

utils::Status common::StreamMenager::getStatus()
{
	return this->status;
}

utils::ErrorCode common::StreamMenager::run()
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::StreamMenager::openStream()
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::StreamMenager::getFromStream()
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::StreamMenager::closeStream()
{
	return utils::ErrorCode::NOK;
}


