/**
 * @file main.cpp
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
#include "Lib_WifiHandler.h"
#include "Lib_SinricProWrapper.h"
#include "Lib_UltrasonicSensor.h"
#include "Lib_CommonDefs.h"

static void Appl_ConvertDistanceToWaterLevelPercent(unsigned int, unsigned char *);
static void Appl_ReadBatteryLevel(unsigned char *);

void setup() 
{
    Serial.begin(BAUD_RATE);
    Lib_PowerManagement_Init();
    Lib_UltrasonicSensor_Init();
    Lib_WifiHandler_Init();
    Lib_SinricProWrapper_Init();
}

void loop() 
{
    static unsigned int distanceMeasuredInCm = 0;
    static unsigned char waterLevelPercent = 0;
    static unsigned char batteryLevelPercent = 0;
    static enum Enum_ReturnState sensorReadingState = E_NOT_OK;
    static bool Flag_UltrasonicSensorDataRequested = FALSE;
    

    if(FALSE == Flag_UltrasonicSensorDataRequested)
    {
        Lib_UltrasonicSensor_RequestData();
        Flag_UltrasonicSensorDataRequested = TRUE;
        Lib_UltrasonicSensor_ReadData(&distanceMeasuredInCm, &sensorReadingState);
        
        
    }
    else
    {
        /* Do nothing */
    }

    /* Stub for now */
    Appl_ReadBatteryLevel(&batteryLevelPercent);
    Lib_SinricProWrapper_UpdateValue(BATTERY_LEVEL, batteryLevelPercent);

    if(E_OK == sensorReadingState)
    {
        Appl_ConvertDistanceToWaterLevelPercent(distanceMeasuredInCm, &waterLevelPercent);
        Lib_SinricProWrapper_UpdateValue(WATER_LEVEL, waterLevelPercent);
        Lib_SinricProWrapper_UpdateValue(BATTERY_LEVEL, batteryLevelPercent);
        Lib_PowerManagement_RequestDeepSleep(POWERMANAGEMENT_DEEPSLEEPTIME_INSECONDS);
        delay(10000);
    }
    else if(E_PENDING == sensorReadingState)
    {
        Lib_UltrasonicSensor_ReadData(&distanceMeasuredInCm, &sensorReadingState);
    }
    else
    {
        Serial.printf("ERR: Ultrasonic Sensor is not initialized\n");
    }
}

static void Appl_ConvertDistanceToWaterLevelPercent(unsigned int distanceMeasuredInCm, unsigned char *waterLevelPercent)
{
    /* Random Logic for now */
    if(30 >= distanceMeasuredInCm)
    {
        *waterLevelPercent = 100;
    }
    else if(40 >= distanceMeasuredInCm)
    {
        *waterLevelPercent = 80;
    }
    else if(50 >= distanceMeasuredInCm)
    {
        *waterLevelPercent = 60;
    }
    else if(60 >= distanceMeasuredInCm)
    {
        *waterLevelPercent = 40;
    }
    else if(70 >= distanceMeasuredInCm)
    {
        *waterLevelPercent = 20;
    }
    else
    {
        *waterLevelPercent = 0;
    }
}

/**
 * @brief Stub for now
 * 
 * @param batteryLevelInPercent 
 */
static void Appl_ReadBatteryLevel(unsigned char *batteryLevelInPercent)
{
    *batteryLevelInPercent = 75;
}