#include <iostream>

#include "headers/Logger.hpp"
#include "headers/LifeCycle.hpp"
#include "headers/StreamMenager.hpp"

int main()
{
    std::cout << "Hello World!\n";

    common::Logger logger;
    common::LifeCycle lifeCycle(&logger);
    common::StreamMenager streamMenager(&logger, &lifeCycle);



}

