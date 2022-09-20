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
#include "Database.h"

/* Global variables */


/**
 * @brief Initialize the Communication Handler
 * 
 */
void IoHandler_Init(void)
{
    /* Initialize GPIO pins */
    pinMode(BUILTIN_LED_PIN, OUTPUT);

    /* Initialize Input/Output Extensions */
    pinMode(LATCH_PIN_74HC595, OUTPUT);
    pinMode(CLOCK_PIN_74HC595, OUTPUT);
    pinMode(DATA_PIN_74HC595, OUTPUT);
}

/**
 * @brief Handle the input pins
 * 
 */
void IoHandler_HandleInputs(void)
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
 * @brief Handle the output pins
 * 
 */
void IoHandler_HandleOutputs(void)
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