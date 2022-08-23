#include <iostream>

#include "headers/Logger.hpp"
#include "headers/LifeCycle.hpp"
#include "headers/ConfigLoader.hpp"
#include "headers/MessageQueue.hpp"
#include "headers/SensorMenager.hpp"
#include "headers/ListenerMenager.hpp"
#include "headers/Sensor.hpp"
#include "headers/Listener.hpp"

int main()
{
    common::Logger logger;
    common::LifeCycle lifeCycle(&logger);
    common::ConfigLoader configLoader(&logger, &lifeCycle);
    common::MessageQueue messageQueue;
    common::SensorMenager sensorMenager(&logger, &lifeCycle, &configLoader, &messageQueue);
    common::ListenerMenager listenerMenager(&logger, &lifeCycle, &configLoader, &messageQueue); 
    
    int a = -1;
    logger.logInfo("Hint: ", "To run program press 0. After run to stop press 1. If you want to exit press 2");
    while (std::cin >> a)
    {
        if (a==0)
        {
            if (lifeCycle.run() == utils::ErrorCode::OK)
            {
                while (std::cin >> a)
                {
                    if (a == 1 || a == 2)
                    {
                        break;
                    }
                }
            }
            else
            {
                logger.logInfo("Hint: ", "Program is stopped cause of an error. To run program press 0, to stop press 2,");
            }
            lifeCycle.stop();
            messageQueue.stop();
            if(a == 1)
                logger.logInfo("Hint: ", "Program is stopped to re run press 0. To exit press 2");
            if (a == 2)
            {
                break;
            }
        }
        if (a == 2)
        {
            break;
        }
    }
}

