/**
* @File LifeCycle.hpp
* @brief: module responsible for set other module to init, start, work and stop
*
* @Owner Damian Panasiuk
*/

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
        LifeCycle() = delete;
        explicit LifeCycle(interface::iLogger* logger);
        virtual ~LifeCycle() = default;

        /**
        * Routine of lifeCycle. ConfigLoader routine will
        * run in main thread. LifeCycle in this function
        * init, start and set work on all services.
        *
        **/
        utils::ErrorCode run() override;
        /**
        * lifeCycle in this function set stop on
        * all services. Run in main thread.
        **/
        utils::ErrorCode stop() override;

        /**
        * If any service want to be active, should
        * registry with this function. All of service 
        * which want to be active have this registry function
        * call in constructor.
        **/
        utils::ErrorCode registry(interface::iLifeCycleService* service);

    private:
        bool isAllServicesInStatus(utils::Status status) const;
        utils::ErrorCode setAllServicesInStatus(utils::Status status) const;

        std::vector<interface::iLifeCycleService* > wantToBeAlive;
        interface::iLogger* logger;
        bool isFirstRun;
    };
}

