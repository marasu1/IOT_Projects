/**
 * @file TimerHandler.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "TimerHandler.h"
#include "InterruptHandler.h"
#include "Scheduler.h"


void TimerHandler_InitTimer(void)
{
    boolean retVal;
    retVal = InterruptHandler_AttachTimerInterrupt(PW_SCHEDULE_CYCLE_TIME);
}