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
    if(DB_ScheduleCounter >= 360000)
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
    retVal = TimerHandler_InitTimer();

    return retVal;
}


/**
 * @brief Scheduler Module Main API
 * 
 */
void Scheduler_Main()
{
  
    /**
     * @brief APIs with 100ms Periodicity
     * 
     */
    if((DB_ScheduleCounter % 10) == 0)
    {
        SinricProWrapper_Handle();
        IoHandler_HandleInputs();
        TouchSensorHandler_Handle();
        
        IoHandler_HandleOutputs();
        
    }

    /**
     * @brief APIs with 250ms Periodicity
     * 
     */
    if((DB_ScheduleCounter % 25) == 0)
    {
        
    }


    /**
     * @brief APIs with 500ms Periodicity
     * 
     */
    if((DB_ScheduleCounter % 50) == 0)
    {

    }

}