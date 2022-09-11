/**
 * @file IoHandler.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef IOHANDLER_H
#define IOHANDLER_H

#include <Arduino.h>
#include "CommonDefs.h"

#define NUM_OF_DIGITAL_PINS 10

#define PIN_IN  0
#define PIN_OUT  1

#define PIN_LOW  0
#define PIN_HIGH  1


/* Global variables */


/* APIs */
extern void IoHandler_Init(void);
extern void IoHandler_HandleInputs(void);
extern void IoHandler_HandleOutputs(void);


#endif