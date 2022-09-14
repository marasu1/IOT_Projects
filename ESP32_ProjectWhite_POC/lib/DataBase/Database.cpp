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
#include "IoHandler.h"

/* Global variables */
unsigned long DB_ScheduleCounter;

bool DB_DigitalPinStatus[10];
bool DB_DigitalPinDir[10];

bool DB_DeviceSwitch01_Status;
bool DB_DeviceFan01_Status;
unsigned char DB_DeviceFan01_Value;

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

    /* Initialize the Device values in database */
    DB_DeviceSwitch01_Status = FALSE;
    DB_DeviceFan01_Status = FALSE;
    DB_DeviceFan01_Value = 0;

}
