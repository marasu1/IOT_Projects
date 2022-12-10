/**
 * @file Lib_PowerManagement.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LIB_POWERMANAGEMENT_H
#define LIB_POWERMANAGEMENT_H

#include "Lib_CommonDefs.h"

#define POWERMANAGEMENT_DEEPSLEEPTIME_INSECONDS 1800u

extern enum Enum_LibState Lib_PowerManagement_State;
extern enum RFMode Lib_PowerManagement_DeepSleepWakeUpOption;

extern void Lib_PowerManagement_Init();
extern void Lib_PowerManagement_Deinit();
extern void Lib_PowerManagement_RequestDeepSleep(unsigned int);




#endif