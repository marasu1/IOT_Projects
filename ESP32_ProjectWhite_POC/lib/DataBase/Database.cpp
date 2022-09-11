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
boolean DB_DigitalPinStatus[10];
boolean DB_DigitalPinDir[10];

/**
 * @brief Initialize the Database
 * 
 */
void Database_Init(void)
{
    DB_ScheduleCounter = 0;

    for(unsigned char pinIndex = 0; pinIndex < NUM_OF_DIGITAL_PINS; pinIndex++)
    {
        DB_DigitalPinDir[pinIndex] = PIN_OUT;
        DB_DigitalPinStatus[pinIndex] = PIN_LOW;
    }
}
