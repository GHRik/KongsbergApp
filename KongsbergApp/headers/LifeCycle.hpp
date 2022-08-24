#pragma once

#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLifeCycleService.hpp"
#include "../interfaces/iLogger.hpp"
#include <vector>


namespace common
{
    class LifeCycle :
        public interface::iLifeCycleMenager
    {
    public:
        LifeCycle() = default;
        LifeCycle(interface::iLogger* logger);
        virtual ~LifeCycle();
        utils::ErrorCode run();
        utils::ErrorCode stop();
        utils::ErrorCode registry(interface::iLifeCycleService* service);

    private:
        bool isAllServicesInStatus(utils::Status status) const;
        utils::ErrorCode setAllServicesInStatus(utils::Status status) const;

        std::vector<interface::iLifeCycleService* > wantToBeAlive;
        interface::iLogger* logger;
        bool isFirstRun;
    };
}

