/**
 * @file Database.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <Arduino.h>



enum DB_TouchSensorStatus_Enum
{
    TOUCH_NO = 0,
    TOUCH_YES
};


/* Global variables */
extern unsigned long DB_ScheduleCounter;
extern bool DB_DigitalPinStatus[];
extern bool DB_DigitalPinDir[];

extern bool DB_DigitalExtensionOutputPinStatus[];

extern bool DB_DeviceSwitch01_Status;
extern bool DB_DeviceFan01_Status;
extern unsigned char DB_DeviceFan01_Value;


extern enum DB_TouchSensorStatus_Enum DB_TouchSensor_Status[];


/* APIs */
extern void Database_Init(void);

#endif