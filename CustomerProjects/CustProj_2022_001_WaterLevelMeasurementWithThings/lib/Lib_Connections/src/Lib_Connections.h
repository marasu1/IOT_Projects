/**
 * @file Lib_Connections.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef LIB_CONNECTIONS_H
#define LIB_CONNECTIONS_H


/*INPUT CONNECTIONS*/
#define PININ_UltrasonicSensor_ECHO 12
#define PININ_BatteryLevel A0
#define PININ_TOTAL_PINS 2


/*OUTPUT CONNECTIONS*/
#define PINOUT_UltrasonicSensor_TRIG 13
#define PINOUT_TOTAL_PINS 1


/* Interfaces of Const pin collection arrays */
extern const unsigned char IoConnections_InputPins[];
extern const unsigned char IoConnections_OutputPins[];


#endif
