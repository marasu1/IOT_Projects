/**
 * @file Scheduler.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Scheduler.h"
#include "TimerHandler.h"
#include "Database.h"
#include "SinricProWrapper.h"
#include "IoHandler.h"
#include "TouchSensorHandler.h"
#include "Application.h"

/**
 * @brief   Callback API
 *          Called only by the TimerHandler module
 *          Called when the set timer is overflown.
 */
void Scheduler_Callback_TimerOverflow()
{
    /* Increment the Schedule Counter from Database */
    DB_ScheduleCounter = DB_ScheduleCounter + 1;
    
    /* Ceiling of Schedule Counter to an hour */
    if(DB_ScheduleCounter >= 3600000)
    {
        DB_ScheduleCounter = 0;
    }
}




/**
 * @brief API to initiate the Scheduler
 * 
 * @return boolean 
 */
boolean Scheduler_Init(void)
{
    boolean retVal = FALSE;

    /**
     * TODO:    Initial checks.
     *          If any one of the checks fail,
     *              retVal = FALSE              AND 
     *              Skip to end
     */

    /* Initiate Timer */
    TimerHandler_InitTimer();

    return retVal;
}


/**
 * @brief Scheduler Module Main API
 * 
 */
void Scheduler_Main()
{

    /**
     * @brief APIs with 2ms Periodicity
     * 
     */
    if((DB_ScheduleCounter % 2) == 0)
    {
        IoHandler_HandleDigitalInputs();
        IoHandler_HandleDigitalOutputs();
    }
    else
    {
        /* Do nothing */
    }

    /**
     * @brief APIs with 10ms Periodicity
     * 
     */
    if((DB_ScheduleCounter % 10) == 0)
    {
        Application_ProcessInputs();
        Application_ProcessOutputs();
    }
    else
    {
        /* Do nothing */
    }

    /**
     * @brief APIs with 100ms Periodicity
     * 
     */
    if((DB_ScheduleCounter % 100) == 0)
    {
        SinricProWrapper_Handle();    
        TouchSensorHandler_Handle();
    }
    else
    {
        /* Do nothing */
    }

    /**
     * @brief APIs with 250ms Periodicity
     * 
     */
    if((DB_ScheduleCounter % 250) == 0)
    {
        IoHandler_HandleIoExtensions();
    }
    else
    {
        /* Do nothing */
    }

    /**
     * @brief APIs with 500ms Periodicity
     * 
     */
    if((DB_ScheduleCounter % 500) == 0)
    {

    }
    else
    {
        /* Do nothing */
    }

}