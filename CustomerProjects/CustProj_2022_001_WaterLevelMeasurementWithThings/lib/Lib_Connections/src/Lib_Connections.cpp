/**
 * @file Lib_Connections.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>
#include "Lib_Connections.h"


const unsigned char IoConnections_InputPins[] = 
{
	PININ_UltrasonicSensor_ECHO,
	PININ_BatteryLevel,
};

const unsigned char IoConnections_OutputPins[] = 
{
	PINOUT_UltrasonicSensor_TRIG,
};

