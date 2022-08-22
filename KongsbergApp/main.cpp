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
    common::ListenerMenager listenerMenager(&logger, &lifeCycle, &messageQueue);
    sensorLayer::Sensor Sensor(&sensorMenager);
    listenerLayer::Listener Listener(&listenerMenager);
    
    if (lifeCycle.run() == utils::ErrorCode::OK)
    {
        int a = -1;
        while (std::cin >> a)
        {
            if (a == 0)
            {
                break;
            }
        }
    }



    lifeCycle.stop();



}

