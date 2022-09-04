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


#include "database.h"


/* Global variables */
unsigned long DB_ScheduleCounter;

/**
 * @brief Initialize the Database
 * 
 */
void Database_Init(void)
{
    DB_ScheduleCounter = 0;
}