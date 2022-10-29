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

#define NUM_OF_EXTENSION_OUTPUT_DIGITAL_PINS 8

#define PIN_IN  0
#define PIN_OUT  1

#define PIN_LOW  0
#define PIN_HIGH  1


/* Input/Output Extension Pins */
#define LATCH_PIN_74HC595 1
#define CLOCK_PIN_74HC595 2
#define DATA_PIN_74HC595 3


/* Global variables */


/* APIs */
extern void IoHandler_Init(void);
extern void IoHandler_HandleDigitalInputs(void);
extern void IoHandler_HandleDigitalOutputs(void);


extern void IoHandler_HandleIoExtensions(void);

#endif