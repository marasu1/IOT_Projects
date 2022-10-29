/**
 * @file Application.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Application.h"
#include "Database.h"
#include "CommonDefs.h"
#include "IoHandler.h"
#include "IoConnections.h"


static unsigned char SpeedChangeDematurationTimer_Fan01 = 0;
static unsigned char SpeedChangeAllowedTimer_Fan01 = 0;
static bool SpeedIncreaseStartFlag_Fan01 = FALSE;
static bool SpeedDecreaseStartFlag_Fan01 = FALSE;
static bool SpeedChangeOngoingFlag_Fan01 = FALSE;
static bool SpeedChangeAllowedFlag_Fan01 = FALSE;

static void Application_ProcessInputTouchSensors();
static void Application_ProcessOutputDevices();
static void Application_ProcessLights();
static void Application_ProcessFans();

void Application_Callback_ZeroCrossing()
{
    


}

void Application_Fan_Control()
{
    /* Implementation for FAN01 */
    unsigned int chopTime = 0;
    
    if(DB_DeviceFan01_Status == TRUE)
    {
        if((DB_DeviceFan01_Value > 0) && (DB_DeviceFan01_Value <= 6))
        {
            chopTime = 1500 * DB_DeviceFan01_Value;     //min chop time is 1500us and max chop time is 9000us
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }
}

void Application_ProcessInputs()
{
    Application_ProcessInputTouchSensors();
}

void Application_ProcessOutputs()
{
    Application_ProcessOutputDevices();


    if(SpeedIncreaseStartFlag_Fan01 == TRUE)
    {
        /* Incrementing this maturation timer by 1 per 10 ms */
        SpeedChangeDematurationTimer_Fan01 = SpeedChangeDematurationTimer_Fan01 + 1;

        if(SpeedChangeDematurationTimer_Fan01 >= 100)
        {
            SpeedIncreaseStartFlag_Fan01 = FALSE;
            SpeedDecreaseStartFlag_Fan01 = FALSE;
            SpeedChangeOngoingFlag_Fan01 = FALSE;
        }
        else
        {
            /* Do nothing */
        }

        if((SpeedChangeAllowedFlag_Fan01 == FALSE) && (SpeedChangeOngoingFlag_Fan01 == TRUE))
        {
            SpeedChangeAllowedTimer_Fan01 = SpeedChangeAllowedTimer_Fan01 + 1;
            if(SpeedChangeAllowedTimer_Fan01 >= 100)
            {
                SpeedChangeAllowedFlag_Fan01 = TRUE;
                SpeedChangeAllowedTimer_Fan01 = 0;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }

    }
    else
    {
        /* Do nothing */
    }

}

static void Application_ProcessInputTouchSensors()
{
    static bool Prev_DigitalPinStatus[PININ_TOTAL_TOUCH_SENSORS];

    for(unsigned char sensorIndex = 0; sensorIndex < PININ_TOTAL_TOUCH_SENSORS; sensorIndex++)
    {
        if( (DB_DigitalPinStatus[IoConnections_InputTouchSensors[sensorIndex]] == PIN_HIGH) &&
            (Prev_DigitalPinStatus[sensorIndex] != PIN_HIGH) )
        {
            DB_TouchSensor_Status[sensorIndex] = TOUCH_YES;
            Prev_DigitalPinStatus[sensorIndex] = PIN_HIGH;
        }
        else if( (DB_DigitalPinStatus[IoConnections_InputTouchSensors[sensorIndex]] == PIN_HIGH) &&
            (Prev_DigitalPinStatus[sensorIndex] == PIN_HIGH) )
        {
            DB_TouchSensor_Status[sensorIndex] = TOUCH_YES_HELD;
        }
        else
        {
            DB_TouchSensor_Status[sensorIndex] = TOUCH_NO;
            Prev_DigitalPinStatus[sensorIndex] = PIN_LOW;
        }
    }
}

static void Application_ProcessOutputDevices()
{
    Application_ProcessLights();
    Application_ProcessFans();
}

static void Application_ProcessLights()
{
    /* Device 01 */
    if((DB_TouchSensor_Status[0] == TOUCH_YES) && (DB_Device01_Light01_Status == FALSE))
    {
        DB_Device01_Light01_Status = TRUE;
    }
    else if((DB_TouchSensor_Status[0] == TOUCH_YES) && (DB_Device01_Light01_Status == TRUE))
    {
        DB_Device01_Light01_Status = FALSE;
    }
    else
    {
        /* Do nothing */
    }

    /* Device 02 */
    if((DB_TouchSensor_Status[1] == TOUCH_YES) && (DB_Device02_Light02_Status == FALSE))
    {
        DB_Device02_Light02_Status = TRUE;
    }
    else if((DB_TouchSensor_Status[1] == TOUCH_YES) && (DB_Device02_Light02_Status == TRUE))
    {
        DB_Device02_Light02_Status = FALSE;
    }
    else
    {
        /* Do nothing */
    }

    /* Device 03 */
    if((DB_TouchSensor_Status[2] == TOUCH_YES) && (DB_Device03_Light03_Status == FALSE))
    {
        DB_Device03_Light03_Status = TRUE;
    }
    else if((DB_TouchSensor_Status[2] == TOUCH_YES) && (DB_Device03_Light03_Status == TRUE))
    {
        DB_Device03_Light03_Status = FALSE;
    }
    else
    {
        /* Do nothing */
    }
}

static void Application_ProcessFans()
{

    /* Device 04 */
    if((DB_TouchSensor_Status[3] == TOUCH_YES) && (DB_Device04_Fan01_Status == FALSE))
    {
        DB_Device04_Fan01_Status = TRUE;
    }
    else if((DB_TouchSensor_Status[3] == TOUCH_YES) && (DB_Device04_Fan01_Status == TRUE))
    {
        DB_Device04_Fan01_Status = FALSE;
    }
    else
    {
        /* Do nothing */
    }

    if((DB_TouchSensor_Status[4] == TOUCH_YES) && (DB_TouchSensor_Status[6] == TOUCH_NO))
    {
        /* FAN Speed decreasing */
        
        SpeedChangeDematurationTimer_Fan01 = 0;


        if(SpeedChangeOngoingFlag_Fan01 == FALSE)
        {
            SpeedIncreaseStartFlag_Fan01 = FALSE;
            SpeedDecreaseStartFlag_Fan01 = TRUE;
        }
        else
        {
            if((DB_DeviceFan01_Value > 0) && (SpeedChangeAllowedFlag_Fan01 == TRUE))
            {
                DB_DeviceFan01_Value = DB_DeviceFan01_Value - 1;
                SpeedChangeAllowedFlag_Fan01 = FALSE;
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else if((DB_TouchSensor_Status[4] == TOUCH_NO) && (DB_TouchSensor_Status[6] == TOUCH_YES))
    {
        /* Fan Speed increasing */
    
        SpeedChangeDematurationTimer_Fan01 = 0;

        if(SpeedChangeOngoingFlag_Fan01 == FALSE)
        {
            SpeedIncreaseStartFlag_Fan01 = TRUE;
            SpeedDecreaseStartFlag_Fan01 = FALSE;
        }
        else
        {
            if((DB_DeviceFan01_Value < 6) && (SpeedChangeAllowedFlag_Fan01 == TRUE))
            {
                DB_DeviceFan01_Value = DB_DeviceFan01_Value + 1;
                SpeedChangeAllowedFlag_Fan01 = FALSE;
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else
    {
        /* Do nothing */
    }

    if(DB_TouchSensor_Status[5] == TOUCH_YES)
    {
        if(SpeedIncreaseStartFlag_Fan01 == TRUE)
        {
            SpeedChangeOngoingFlag_Fan01 = TRUE;
        }
    }
    else
    {
        /* Do nothing */
    }

}