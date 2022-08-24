#include "../headers/LifeCycle.hpp"

common::LifeCycle::LifeCycle(interface::iLogger* logger)
	: logger(logger), isFirstRun(true)
{
}

common::LifeCycle::~LifeCycle()
{
}

utils::ErrorCode common::LifeCycle::run()
{
	if (isAllServicesInStatus(utils::Status::CREATE) == false && isFirstRun == true)
	{
		logger->logError("After CREATE", "Some of services dont start corectly");
		return utils::ErrorCode::NOK;
	}
	if (setAllServicesInStatus(utils::Status::INIT) == utils::ErrorCode::OK && isAllServicesInStatus(utils::Status::INIT) == true)
	{
		if (setAllServicesInStatus(utils::Status::START) == utils::ErrorCode::OK && isAllServicesInStatus(utils::START) == true)
		{
			if (setAllServicesInStatus(utils::Status::WORK) == utils::ErrorCode::OK && isAllServicesInStatus(utils::Status::WORK) == true)
			{
				isFirstRun = false;
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

bool common::LifeCycle::isAllServicesInStatus(utils::Status status) const
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

utils::ErrorCode common::LifeCycle::setAllServicesInStatus(utils::Status status) const
{
	for (int i = 0; i < wantToBeAlive.size(); ++i)
	{
		if (wantToBeAlive.at(i)->setStatus(status) != utils::ErrorCode::OK)
		{
			logger->logError(utils::ToString(status), "Unable to run service " + std::to_string(i+1));
			return utils::ErrorCode::NOK;
		}
	}

	return utils::ErrorCode::OK;
}
