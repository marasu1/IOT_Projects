/**
 * @file IoConnections.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "IoConnections.h"

const unsigned char IoConnections_InputPins[] = 
{
    PININ_TOUCH_SENSOR_01,
    PININ_TOUCH_SENSOR_02,
    PININ_TOUCH_SENSOR_03,
    PININ_TOUCH_SENSOR_04,
    PININ_TOUCH_SENSOR_05,
    PININ_TOUCH_SENSOR_06,
    PININ_TOUCH_SENSOR_07,
    PININ_AC_ZERO_CROSSING_SENSOR,
    PININ_DEVICE_FEEDBACK_01,
    PININ_DEVICE_FEEDBACK_02,
    PININ_DEVICE_FEEDBACK_03,
    PININ_DEVICE_FEEDBACK_04,
};

const unsigned char IoConnections_OutputPins[] = 
{
    PINOUT_LED_INDICATION_01,
    PINOUT_74HC595_LATCH,
    PINOUT_74HC595_CLOCK,
    PINOUT_74HC595_DATA,
    PINOUT_LED_INDICATION_02,
    PINOUT_LED_INDICATION_03,
    PINOUT_LED_INDICATION_04,
    PINOUT_DEVICE_OUTPUT_01,
    PINOUT_DEVICE_OUTPUT_02,
    PINOUT_DEVICE_OUTPUT_03,
    PINOUT_DEVICE_OUTPUT_04,
};

const unsigned char IoConnections_InputTouchSensors[] = 
{
    PININ_TOUCH_SENSOR_01,
    PININ_TOUCH_SENSOR_02,
    PININ_TOUCH_SENSOR_03,
    PININ_TOUCH_SENSOR_04,
    PININ_TOUCH_SENSOR_05,
    PININ_TOUCH_SENSOR_06,
    PININ_TOUCH_SENSOR_07,
};

const unsigned char IoConnections_InputDeviceFeedbacks[] = 
{
    PININ_DEVICE_FEEDBACK_01,
    PININ_DEVICE_FEEDBACK_02,
    PININ_DEVICE_FEEDBACK_03,
    PININ_DEVICE_FEEDBACK_04,
};

const unsigned char IoConnections_OutputLedIndications[] = 
{
    PINOUT_LED_INDICATION_01,
    PINOUT_LED_INDICATION_02,
    PINOUT_LED_INDICATION_03,
    PINOUT_LED_INDICATION_04,
};

const unsigned char IoConnections_OutputDeviceOutputs[] = 
{
    PINOUT_DEVICE_OUTPUT_01,
    PINOUT_DEVICE_OUTPUT_02,
    PINOUT_DEVICE_OUTPUT_03,
    PINOUT_DEVICE_OUTPUT_04,
};