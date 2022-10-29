/**
 * @file IoHandler.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "IoHandler.h"
#include "InterruptHandler.h"
#include "Database.h"
#include "IoConnections.h"

/* Global variables */


/**
 * @brief Initialize the Communication Handler
 * 
 */
void IoHandler_Init(void)
{
    /* Initialize Input Pins */
    for(unsigned char index = 0; index < PININ_TOTAL_PINS; index++)
    {
        pinMode(IoConnections_InputPins[index], INPUT);
        DB_DigitalPinDir[index] = PIN_IN;
    }

    /* Initialize Output Pins */
    for(unsigned char index = 0; index < PINOUT_TOTAL_PINS; index++)
    {
        pinMode(IoConnections_OutputPins[index], OUTPUT);
        DB_DigitalPinDir[index] = PIN_OUT;
        DB_DigitalPinStatus[index] = PIN_LOW;
    }

    InterruptHandler_AttachDigitalPinInterrupt(PININ_AC_ZERO_CROSSING_SENSOR);
}

/**
 * @brief Handle the digital   input pins
 * 
 */
void IoHandler_HandleDigitalInputs(void)
{
    unsigned char pinIndex = 0;

    for(pinIndex = 0; pinIndex < NUM_OF_DIGITAL_PINS; pinIndex++)
    {
        if(DB_DigitalPinDir[pinIndex] == PIN_IN)
        {
            DB_DigitalPinStatus[pinIndex] = digitalRead(pinIndex);
        }
        else
        {
            /* Do nothing */
        }
    }
}

/**
 * @brief Handle the digital output pins
 * 
 */
void IoHandler_HandleDigitalOutputs(void)
{
    unsigned char pinIndex = 0;

    for(pinIndex = 0; pinIndex < NUM_OF_DIGITAL_PINS; pinIndex++)
    {
        if(DB_DigitalPinDir[pinIndex] == PIN_OUT)
        {
            digitalWrite(pinIndex, DB_DigitalPinStatus[pinIndex]);
        }
        else
        {
            /* Do nothing */
        }
    }

}

/**
 * @brief Handle Input/Output extensions
 * 
 */
void IoHandler_HandleIoExtensions(void)
{ 
    /**
     * @brief Handle 74HC595
     * 
     */

    unsigned char pinIndex = 0;
    

    for(pinIndex = 0; pinIndex < NUM_OF_EXTENSION_OUTPUT_DIGITAL_PINS; pinIndex++)
    {
        byte bitsToSend = 0;
        
        // turn off the output
        digitalWrite(LATCH_PIN_74HC595, LOW);
        // turn on the next highest bit in bitsToSend:
        bitWrite(bitsToSend, pinIndex, DB_DigitalExtensionOutputPinStatus[pinIndex]);
        // shift the bits out:
        shiftOut(DATA_PIN_74HC595, CLOCK_PIN_74HC595, MSBFIRST, bitsToSend);
        // turn on the output so the LEDs can light up:
        digitalWrite(LATCH_PIN_74HC595, HIGH);
    }

}
