# Kongsberg - App

## Table of contents
1. [ Description ](#des)
2. [ Set config ](#config)
3. [ Architecture ](#archi)
4. [ Features ](#fea)
5. [ To-Dos ](#todo)
6. [ Results ](#res)

<a name="des">.</a>
## Description

In this task i have to create a program which one:
- Take config from json file
- Analize config file
- Create sensors with param from config file
- Create sensors listeners which one take all sensors data
- Wrapp data with special way
- Print wrapp data

Program was created and additional some feature was added(check below). 

<a name="config">.</a>
## Set config
An attempt has been made to support any bad json format. If any case this program will not work check json format this way:
- Key: "Sensors"
- Value: ID(UNIQUE Unsigned integer from 0 to 254)
- Value: Type: (string, name of sensor)
- Value: MinValue (integer, minimum value which can sensor create)
- Value MaxValue (integer, maximum value which can sensor create)
- Value: Alive (boolean, is sensor is turn off or turn on)
- Value: FrequencyHZ(unsigned integer, how fast you can take a data from sensor in Hz)
Example json config you can find in this repo [SensorConfig.json](https://github.com/GHRik/KongsbergApp/blob/master/KongsbergApp/SensorConfig.json)

<a name="archi">.</a>
## Architecture

<p align="center">
   <img src="https://github.com/GHRik/KongsbergApp/blob/master/KongsbergApp/images/ArchitecturePreview.png" width="50%" height="50%" /><br \>
</p>

<p align="center">
   <img src="https://github.com/GHRik/KongsbergApp/blob/master/KongsbergApp/images/StartProgram.PNG" width="50%" height="50%" /><br \>
</p>

<p align="center">
   <img src="https://github.com/GHRik/KongsbergApp/blob/master/KongsbergApp/images/GetConfig.png" width="50%" height="50%" /><br \>
</p>

<p align="center">
   <img src="https://github.com/GHRik/KongsbergApp/blob/master/KongsbergApp/images/FlowMessage.PNG" width="50%" height="50%" /><br \>
</p>

<a name="fea">.</a>
## Feature
- Use [json library](https://github.com/nlohmann/json)
- Use json config
- Change json config during program run
- Validate json(key and values)
- Easy to change name of key and value in json(check [utils/config.hpp](https://github.com/GHRik/KongsbergApp/blob/master/KongsbergApp/utils/config.hpp))

<a name="Todo">.</a>
## ToDos
- Sometimes program stop. It can be a problem with vector. In my opinion in task like that should be avoid to use vectors. Circular buffer should be use.
- ErrorCode should be validate in all necessary function. On this moment some of functions who are return ErrorCode only return OK.
- All necessary pointers should be change on smart pointers.
- Function run() in ConfigLoader is so big. Should be split by functions.
- Create unit tests. Unit tests class should in first time 
- Delete unecessary pointer, value, log, etc.
- Add logging in any part. At first debugg logs.

<a name="res">.</a>
## Result

