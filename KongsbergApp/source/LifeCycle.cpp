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
	if (setAllServicesInStatus(utils::Status::INIT) == utils::ErrorCode::OK && isAllServicesInStatus(utils::Status::INIT) == true)
	{
		if (setAllServicesInStatus(utils::Status::START) == utils::ErrorCode::OK && isAllServicesInStatus(utils::START) == true)
		{
			if (setAllServicesInStatus(utils::Status::WORK) == utils::ErrorCode::OK && isAllServicesInStatus(utils::Status::WORK) == true)
			{
				return utils::ErrorCode::OK;
			}
			else
			{
				logger->logError("After WORK", "Some of services dont start corectly");
			}
		}
		else
		{
			logger->logError("After START", "Some of services dont start corectly");
			return utils::ErrorCode::NOK;
		}
	}
	else
	{
		logger->logError("INIT", "Problem init service " + std::to_string(wantToBeAlive.size()));
	}
	return utils::ErrorCode::NOK;
}

utils::ErrorCode common::LifeCycle::stop()
{
	setAllServicesInStatus(utils::Status::STOP);
	return utils::ErrorCode::OK;
}


utils::ErrorCode common::LifeCycle::registry(interface::iLifeCycleService* service)
{
	wantToBeAlive.push_back(service);
	return utils::ErrorCode::OK;
}

bool common::LifeCycle::isAllServicesInStatus(utils::Status status)
{
	for(int i = 0; i < wantToBeAlive.size(); ++i)
	{
		if (wantToBeAlive.at(i)->getStatus() != status)
		{
			return false;
		}
	}
	return true;
}

utils::ErrorCode common::LifeCycle::setAllServicesInStatus(utils::Status status)
{
	for (int i = 0; i < wantToBeAlive.size(); ++i)
	{
		if (wantToBeAlive.at(i) == nullptr)
			logger->logError("Null", "Ptr");
		if (wantToBeAlive.at(i)->setStatus(status) != utils::ErrorCode::OK)
		{
			logger->logError(utils::ToString(status), "Unable to run service " + std::to_string(i+1));
			return utils::ErrorCode::NOK;
		}
	}

	return utils::ErrorCode::OK;
}
