/**
 * @file TouchSensorHandler.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "TouchSensorHandler.h"
#include "Database.h"
#include "IoHandler.h"

/* Global variables */
static const TouchSensorStruct TouchSensors[NUMBER_OF_TOUCH_SENSORS] = 
{
    {
        TTP223,
        DIRECT_ACTIVE_HIGH,
        DB_SENSOR01_IP_PIN
    },
    {
        TTP223,
        DIRECT_ACTIVE_HIGH,
        DB_SENSOR02_IP_PIN
    },
    {
        TTP223,
        DIRECT_ACTIVE_HIGH,
        DB_SENSOR03_IP_PIN
    },
    {
        TTP223,
        DIRECT_ACTIVE_HIGH,
        DB_SENSOR04_IP_PIN
    },
    {
        TTP223,
        DIRECT_ACTIVE_HIGH,
        DB_SENSOR05_IP_PIN
    }
};

/**
 * @brief Initialize the TouchSensorHandler
 * 
 */
void TouchSensorHandler_Init(void)
{
    for(unsigned char touchSensorIndex = 0; touchSensorIndex < NUMBER_OF_TOUCH_SENSORS; touchSensorIndex++)
    {
        if(TouchSensors[touchSensorIndex].sensorType == TTP223)
        {
            if(TouchSensors[touchSensorIndex].sensorMode == DIRECT_ACTIVE_HIGH)
            {
                DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorOutputPin01FromDB] = PIN_LOW;
                DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorOutputPin02FromDB] = PIN_LOW;
                DB_TouchSensor_Status[touchSensorIndex] = TOUCH_NO;
            }
            else if(TouchSensors[touchSensorIndex].sensorMode == DIRECT_ACTIVE_LOW)
            {
                DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorOutputPin01FromDB] = PIN_LOW;
                DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorOutputPin02FromDB] = PIN_HIGH;
                DB_TouchSensor_Status[touchSensorIndex] = TOUCH_NO;
            }
            else if(TouchSensors[touchSensorIndex].sensorMode == TOGGLE_INIT_LOW)
            {
                DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorOutputPin01FromDB] = PIN_HIGH;
                DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorOutputPin02FromDB] = PIN_LOW;
                DB_TouchSensor_Status[touchSensorIndex] = TOUCH_NO;
            }
            else if(TouchSensors[touchSensorIndex].sensorMode == TOGGLE_INIT_HIGH)
            {
                DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorOutputPin01FromDB] = PIN_HIGH;
                DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorOutputPin02FromDB] = PIN_HIGH;
                DB_TouchSensor_Status[touchSensorIndex] = TOUCH_YES;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
}

/**
 * @brief Handle the Touch Sensor inputs
 * 
 */
void TouchSensorHandler_Handle(void)
{
    for(unsigned char touchSensorIndex = 0; touchSensorIndex < NUMBER_OF_TOUCH_SENSORS; touchSensorIndex++)
    {
        if(TouchSensors[touchSensorIndex].sensorType == TTP223)
        {
            if(TouchSensors[touchSensorIndex].sensorMode == DIRECT_ACTIVE_HIGH)
            {
                if(DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorInputPinFromDB] == PIN_HIGH)
                {
                    DB_TouchSensor_Status[touchSensorIndex] = TOUCH_YES;
                }
                else
                {
                    DB_TouchSensor_Status[touchSensorIndex] = TOUCH_NO;
                }
            }
            else if(TouchSensors[touchSensorIndex].sensorMode == DIRECT_ACTIVE_LOW)
            {
                if(DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorInputPinFromDB] == PIN_HIGH)
                {
                    DB_TouchSensor_Status[touchSensorIndex] = TOUCH_NO;
                }
                else
                {
                    DB_TouchSensor_Status[touchSensorIndex] = TOUCH_YES;
                }
            }
            else if((TouchSensors[touchSensorIndex].sensorMode == TOGGLE_INIT_LOW)  ||
                    (TouchSensors[touchSensorIndex].sensorMode == TOGGLE_INIT_HIGH) )
            {
                if(DB_DigitalPinStatus[TouchSensors[touchSensorIndex].sensorInputPinFromDB] == PIN_HIGH)
                {
                    if(DB_TouchSensor_Status[touchSensorIndex] == TOUCH_YES)
                    {
                        DB_TouchSensor_Status[touchSensorIndex] = TOUCH_NO;
                    }
                    else if(DB_TouchSensor_Status[touchSensorIndex] == TOUCH_NO)
                    {
                        DB_TouchSensor_Status[touchSensorIndex] = TOUCH_YES;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
}