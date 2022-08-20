#include "../headers/LifeCycle.hpp"

common::LifeCycle::LifeCycle(interface::iLogger* logger)
{
	this->logger = logger;
}

common::LifeCycle::~LifeCycle()
{
	this->stop();
}

utils::ErrorCode common::LifeCycle::run()
{
	for (int i = 0; i < wantToBeAlive.size(); ++i)
	{
		wantToBeAlive.at(i)->setStatus(utils::Status::START);
		wantToBeAlive.at(i)->run();


	}
	return utils::ErrorCode::OK;
}

utils::ErrorCode common::LifeCycle::stop()
{
	for (int i = 0; i < wantToBeAlive.size(); ++i)
	{

		wantToBeAlive.at(i)->setStatus(utils::Status::STOP);
	}
	return utils::ErrorCode::OK;
}


utils::ErrorCode common::LifeCycle::registry(interface::iLifeCycleService* service)
{
	wantToBeAlive.push_back(service);
	return utils::ErrorCode::NOK;
}
