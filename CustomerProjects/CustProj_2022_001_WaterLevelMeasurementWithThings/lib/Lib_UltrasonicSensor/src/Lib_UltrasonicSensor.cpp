/**
 * @file Lib_UltrasonicSensor.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>
#include "Lib_UltrasonicSensor.h"
#include "Lib_Connections.h"

enum Enum_LibState Lib_UltrasonicSensor_State = UNINIT;

static unsigned int UltrasonicSensor_PulseResponseDuration = 0;

/**
 * @brief API for initializing Ultrasonic Sensor Lib
 * 
 */
void Lib_UltrasonicSensor_Init()
{
    pinMode(PINOUT_UltrasonicSensor_TRIG, OUTPUT);
    pinMode(PININ_UltrasonicSensor_ECHO, INPUT);

    Lib_UltrasonicSensor_State = INIT;
}

/**
 * @brief API for de-initializing Ultrasonic Sensor Lib
 * 
 */
void Lib_UltrasonicSensor_Deinit()
{


    Lib_UltrasonicSensor_State = DEINIT;
}

/**
 * @brief API for requesting data from Ultrasonic Sensor
 * 
 */
void Lib_UltrasonicSensor_RequestData()
{
    if(INIT == Lib_UltrasonicSensor_State)
    {
        digitalWrite(PINOUT_UltrasonicSensor_TRIG, HIGH);
        delayMicroseconds(10);
        digitalWrite(PINOUT_UltrasonicSensor_TRIG, LOW);

        UltrasonicSensor_PulseResponseDuration = pulseIn(PININ_UltrasonicSensor_ECHO, HIGH);
    }
    else
    {
        /* Do nothing */
    }
}

/**
 * @brief API for reading data from the Ultrasonic Sensor
 * 
 */
void Lib_UltrasonicSensor_ReadData(unsigned int *distanceInCm, enum Enum_ReturnState *sensorReadingState)
{
    if(INIT == Lib_UltrasonicSensor_State)
    {
        if(UltrasonicSensor_PulseResponseDuration != 0)
        {
            *distanceInCm = UltrasonicSensor_PulseResponseDuration / 58;
            *sensorReadingState = E_OK;
        }
        else
        {
            *distanceInCm = 0;
            *sensorReadingState = E_PENDING;
        }
    }
    else
    {
        *sensorReadingState = E_NOT_OK;
    }
}
