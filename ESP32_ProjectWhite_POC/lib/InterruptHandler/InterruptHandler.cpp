/**
 * @file InterruptHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Ticker.h>
#include "Scheduler.h"
#include "IoHandler.h"
#include "IoConnections.h"
#include "Application.h"

Ticker jobTicker;

static void localTimerOverflowCallout()
{
    Scheduler_Callback_TimerOverflow();
}

static void localDioZeroCrossingCallout()
{
    Application_Callback_ZeroCrossing();
}

boolean InterruptHandler_AttachTimerInterrupt(unsigned int cycleTimeMs)
{
    boolean retVal = FALSE;

    jobTicker.attach_ms(cycleTimeMs, localTimerOverflowCallout);
    retVal = TRUE;

    return retVal;
}

boolean InterruptHandler_AttachDigitalPinInterrupt(unsigned int pinIndex)
{
    boolean retVal = FALSE;

    if(pinIndex == PININ_AC_ZERO_CROSSING_SENSOR)
    {
        attachInterrupt(digitalPinToInterrupt(pinIndex), localDioZeroCrossingCallout, CHANGE);
        retVal = TRUE;
    }
    else
    {

    }

    return retVal;
}
