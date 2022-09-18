/**
 * @file TouchSensorHandler.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TOUCHSENSORHANDLER_H
#define TOUCHSENSORHANDLER_H

#include <Arduino.h>
#include "CommonDefs.h"

#define NUMBER_OF_TOUCH_SENSORS  5

#define DB_SENSOR01_IP_PIN 5
#define DB_SENSOR01_OP1_PIN 1       //Dummy for now //For TTP223, PIN TOG
#define DB_SENSOR01_OP2_PIN 1       //Dummy for now //For TTP223, PIN AHLB


#define DB_SENSOR02_IP_PIN 6
#define DB_SENSOR02_OP1_PIN 1       //Dummy for now //For TTP223, PIN TOG
#define DB_SENSOR02_OP2_PIN 1       //Dummy for now //For TTP223, PIN AHLB

#define DB_SENSOR03_IP_PIN 7
#define DB_SENSOR03_OP1_PIN 1       //Dummy for now //For TTP223, PIN TOG
#define DB_SENSOR03_OP2_PIN 1       //Dummy for now //For TTP223, PIN AHLB

#define DB_SENSOR04_IP_PIN 8
#define DB_SENSOR04_OP1_PIN 1       //Dummy for now //For TTP223, PIN TOG
#define DB_SENSOR04_OP2_PIN 1       //Dummy for now //For TTP223, PIN AHLB

#define DB_SENSOR05_IP_PIN 9
#define DB_SENSOR05_OP1_PIN 1       //Dummy for now //For TTP223, PIN TOG
#define DB_SENSOR05_OP2_PIN 1       //Dummy for now //For TTP223, PIN AHLB

typedef void (*fptr_TouchSensorEvent_cbk)(void);

enum TouchSensorType
{
    TTP223 = 0,
    NUM_OF_TOUCH_SENSOR_TYPES
};

enum TouchSensorHandlingMode
{
    DIRECT_ACTIVE_HIGH = 0,
    DIRECT_ACTIVE_LOW,
    TOGGLE_INIT_LOW,
    TOGGLE_INIT_HIGH,
    NUM_OF_TOUCH_SENSOR_HANDLING_MODES
};

typedef struct TouchSensorStruct
{
    enum TouchSensorType sensorType;
    enum TouchSensorHandlingMode sensorMode;
    unsigned char sensorInputPinFromDB;
    unsigned char sensorOutputPin01FromDB;
    unsigned char sensorOutputPin02FromDB;
} TouchSensorStruct;


/* Global variables */


/* APIs */
extern void TouchSensorHandler_Init(void);
extern void TouchSensorHandler_Handle(void);

#endif