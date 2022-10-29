/**
 * @file Database.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Database.h"
#include "TouchSensorHandler.h"
#include "IoHandler.h"

/* Global variables */
unsigned long DB_ScheduleCounter;

bool DB_DigitalPinStatus[NUM_OF_DIGITAL_PINS];
bool DB_DigitalPinDir[NUM_OF_DIGITAL_PINS];

bool DB_DigitalExtensionOutputPinStatus[NUM_OF_EXTENSION_OUTPUT_DIGITAL_PINS];

bool DB_DeviceSwitch01_Status;
bool DB_DeviceFan01_Status;
unsigned char DB_DeviceFan01_Value;

bool DB_Device01_Light01_Status;
bool DB_Device02_Light02_Status;
bool DB_Device03_Light03_Status;
bool DB_Device04_Fan01_Status;


enum DB_TouchSensorStatus_Enum DB_TouchSensor_Status[NUMBER_OF_TOUCH_SENSORS];

/**
 * @brief Initialize the Database
 * 
 */
void Database_Init(void)
{
    DB_ScheduleCounter = 0;

    /* Initialize the digital Pin directions and values in database */
    for(unsigned char pinIndex = 0; pinIndex < NUM_OF_DIGITAL_PINS; pinIndex++)
    {
        DB_DigitalPinDir[pinIndex] = PIN_OUT;
        DB_DigitalPinStatus[pinIndex] = PIN_LOW;
    }


    /* Initialize the Touch Sensor Status in database */
    for(unsigned char touchSensorIndex = 0; touchSensorIndex < NUMBER_OF_TOUCH_SENSORS; touchSensorIndex++)
    {
        DB_TouchSensor_Status[touchSensorIndex] = TOUCH_NO;
    }

    /* Initialize the Device values in database */
    DB_DeviceSwitch01_Status = FALSE;
    DB_DeviceFan01_Status = FALSE;
    DB_DeviceFan01_Value = 0;

}
