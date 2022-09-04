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

#include <Ticker.h>
#include "TimerHandler.h"
#include "Scheduler.h"


Ticker jobTicker;

static void localTimerOverflowCallout()
{
    Scheduler_Callback_TimerOverflow();
}

boolean TimerHandler_InitTimer(void)
{
    boolean retVal = FALSE;

    jobTicker.attach_ms(PW_SCHEDULE_CYCLE_TIME, localTimerOverflowCallout);
    retVal = TRUE;

    return retVal;
}