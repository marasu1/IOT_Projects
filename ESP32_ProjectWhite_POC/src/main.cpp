/**
 * @file main.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "CommonDefs.h"
#include "Scheduler.h"
#include "Database.h"
#include "SinricProWrapper.h"
#include "WifiHandler.h"
#include "CommunicationHandler.h"
#include "IoHandler.h"
#include "TouchSensorHandler.h"

void setup() 
{
    /**
     * @brief Init Project
     * 
     */

    Database_Init();
    (void)Scheduler_Init();
    CommunicationHandler_Init();
    IoHandler_Init();
    WifiHandler_Init();
    TouchSensorHandler_Init();
    SinricProWrapper_Init();
}

void loop()
{
    Scheduler_Main();
}
