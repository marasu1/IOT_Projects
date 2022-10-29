#ifndef IOCONNECTIONS_H
#define IOCONNECTIONS_H


/*INPUT CONNECTIONS*/
#define PININ_TOUCH_SENSOR_01 4
#define PININ_TOUCH_SENSOR_02 5
#define PININ_TOUCH_SENSOR_03 15
#define PININ_TOUCH_SENSOR_04 16
#define PININ_TOUCH_SENSOR_05 17
#define PININ_TOUCH_SENSOR_06 18
#define PININ_TOUCH_SENSOR_07 19
#define PININ_AC_ZERO_CROSSING_SENSOR 21
#define PININ_DEVICE_FEEDBACK_01 34
#define PININ_DEVICE_FEEDBACK_02 35
#define PININ_DEVICE_FEEDBACK_03 36
#define PININ_DEVICE_FEEDBACK_04 39


/*OUTPUT CONNECTIONS*/
#define PINOUT_LED_INDICATION_01 2
#define PINOUT_74HC595_LATCH 12
#define PINOUT_74HC595_CLOCK 13
#define PINOUT_74HC595_DATA 14
#define PINOUT_LED_INDICATION_02 22
#define PINOUT_LED_INDICATION_03 23
#define PINOUT_LED_INDICATION_04 25
#define PINOUT_DEVICE_OUTPUT_01 26
#define PINOUT_DEVICE_OUTPUT_02 27
#define PINOUT_DEVICE_OUTPUT_03 32
#define PINOUT_DEVICE_OUTPUT_04 33



#define PININ_TOTAL_TOUCH_SENSORS 7
#define PININ_TOTAL_DEVICE_FEEDBACKS 4
#define PININ_TOTAL_PINS 12

#define PINOUT_TOTAL_LED_INDICATIONS 4
#define PINOUT_TOTAL_DEVICE_OUTPUTS 4
#define PINOUT_TOTAL_PINS 11



/* Interfaces of Const pin collection arrays */
extern const unsigned char IoConnections_InputPins[];
extern const unsigned char IoConnections_OutputPins[];
extern const unsigned char IoConnections_InputTouchSensors[];
extern const unsigned char IoConnections_InputDeviceFeedbacks[];
extern const unsigned char IoConnections_OutputLedIndications[];
extern const unsigned char IoConnections_OutputDeviceOutputs[];

#endif