#include <iostream>

#include "headers/Logger.hpp"
#include "headers/LifeCycle.hpp"
#include "headers/StreamMenager.hpp"
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
    common::StreamMenager streamMenager(&logger, &lifeCycle);
    common::ConfigLoader configLoader(&logger, &lifeCycle, &streamMenager);
    common::MessageQueue messageQueue(&logger, &lifeCycle);
    common::SensorMenager sensorMenager(&logger, &lifeCycle, &configLoader, &messageQueue);
    common::ListenerMenager listenerMenager(&logger, &lifeCycle, &messageQueue);
    sensorLayer::Sensor Sensor(&sensorMenager);
    listenerLayer::Listener Listener(&listenerMenager);



}

