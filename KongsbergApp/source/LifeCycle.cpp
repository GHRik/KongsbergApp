#include "../headers/LifeCycle.hpp"

common::LifeCycle::LifeCycle(interface::iLogger* logger)
{
	this->logger = logger;
}

common::LifeCycle::~LifeCycle()
{
}

utils::ErrorCode common::LifeCycle::run()
{
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::LifeCycle::stop()
{
	return utils::ErrorCode::NOK;
}


utils::ErrorCode common::LifeCycle::registry(interface::iLifeCycleService* service)
{
	wantToBeAlive.push_back(service);
	return utils::ErrorCode::NOK;
}
