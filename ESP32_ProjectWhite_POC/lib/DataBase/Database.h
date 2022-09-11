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
extern boolean DB_DigitalPinStatus[10];
extern boolean DB_DigitalPinDir[10];

/* APIs */
extern void Database_Init(void);

#endif