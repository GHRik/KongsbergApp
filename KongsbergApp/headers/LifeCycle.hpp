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
        LifeCycle(interface::iLogger* logger);
        virtual ~LifeCycle();
        utils::ErrorCode run();
        utils::ErrorCode stop();
        utils::ErrorCode registry(interface::iLifeCycleService* service);

    private:
        std::vector<interface::iLifeCycleService* > wantToBeAlive;
        interface::iLogger* logger;
        utils::Status status;
    };
}

