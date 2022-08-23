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
    std::cout << "Hello World!\n";

    common::Logger logger;
    common::LifeCycle lifeCycle(&logger);
    common::ConfigLoader configLoader(&logger, &lifeCycle);
    common::MessageQueue messageQueue;
    common::SensorMenager sensorMenager(&logger, &lifeCycle, &configLoader, &messageQueue);
    common::ListenerMenager listenerMenager(&logger, &lifeCycle, &configLoader, &messageQueue); 
    
    int a = -1;
    logger.logInfo("Hint: ", "To run program press 0, to stop press 1");
    while (std::cin >> a)
    {
        if (a==0)
        {
            if (lifeCycle.run() == utils::ErrorCode::OK)
            {
                while (std::cin >> a)
                {
                    if (a == 1)
                    {
                        logger.logInfo("INFO: ", "Program is stopped to re run press 0");
                        break;
                    }
                }
            }
            lifeCycle.stop();
        }
    }



    lifeCycle.stop();



}

