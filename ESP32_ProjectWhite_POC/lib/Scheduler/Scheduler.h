/**
 * @file Scheduler.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>
#include "CommonDefs.h"

/* APIs */
extern boolean Scheduler_Init(void);
extern void Scheduler_Main(void);

/* Callbacks  */
extern void Scheduler_Callback_TimerOverflow(void);



#endif