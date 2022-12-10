/**
 * @file Lib_PowerManagement.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>
#include "Lib_PowerManagement.h"

enum Enum_LibState Lib_PowerManagement_State = UNINIT;
enum RFMode Lib_PowerManagement_DeepSleepWakeUpOption = RF_DEFAULT;

/**
 * @brief API for initializing the PowerManagement Lib
 * 
 */
void Lib_PowerManagement_Init()
{
    Lib_PowerManagement_DeepSleepWakeUpOption = RF_CAL;

    Lib_PowerManagement_State = INIT;
}

/**
 * @brief API for de-initializing the PowerManagement Lib
 * 
 */
void Lib_PowerManagement_Deinit()
{
    

    Lib_PowerManagement_State = DEINIT;
}

/**
 * @brief API for requesting Deep Sleep Mode of ESP
 * 
 * @param timeToWakeInSeconds 
 */
void Lib_PowerManagement_RequestDeepSleep(unsigned int timeToWakeInSeconds)
{
    if(INIT == Lib_PowerManagement_State)
    {
        ESP.deepSleep(timeToWakeInSeconds * 1e6, Lib_PowerManagement_DeepSleepWakeUpOption);
    }
    else
    {
        /* Do nothing */
    }
}