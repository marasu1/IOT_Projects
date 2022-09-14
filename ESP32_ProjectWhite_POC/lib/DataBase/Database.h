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

/* Global variables */
extern unsigned long DB_ScheduleCounter;
extern bool DB_DigitalPinStatus[10];
extern bool DB_DigitalPinDir[10];

extern bool DB_DeviceSwitch01_Status;
extern bool DB_DeviceFan01_Status;
extern unsigned char DB_DeviceFan01_Value;

/* APIs */
extern void Database_Init(void);

#endif