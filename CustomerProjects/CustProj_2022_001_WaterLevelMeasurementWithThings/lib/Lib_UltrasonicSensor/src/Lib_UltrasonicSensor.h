/**
 * @file Lib_UltrasonicSensor.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LIB_ULTRASONICSENSOR_H
#define LIB_ULTRASONICSENSOR_H

#include "Lib_CommonDefs.h"

extern enum Enum_LibState Lib_UltrasonicSensor_State;


extern void Lib_UltrasonicSensor_Init();
extern void Lib_UltrasonicSensor_Deinit();
extern void Lib_UltrasonicSensor_RequestData();
extern void Lib_UltrasonicSensor_ReadData(unsigned int *, enum Enum_ReturnState *);


#endif