/**
 * @file Lib_SinricProWrapper.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LIB_SINRICPROWRAPPER_H
#define LIB_SINRICPROWRAPPER_H

#include "Lib_CommonDefs.h"

#define APP_KEY    "13d19ffd-0d04-458c-835a-71f8a7e6fa24"
#define APP_SECRET "c1981d54-899a-441c-a7cb-d7f4b1378758-04d5e0f0-6acf-44e6-ac2e-c2f4526fc9d7"
#define DEVICE_ID  "6394a09db8a7fefbd65ae2c8"

#define SINRICPRO_WATER_LEVEL_RANGE     "rangeInstance1"
#define SINRICPRO_BATTERY_LEVEL_RANGE   "rangeInstance2"


enum Enum_SinricPro_RangeType
{
    WATER_LEVEL = 0,
    BATTERY_LEVEL,
    NUMBER_OF_RANGETYPES
};

extern enum Enum_SinricPro_RangeType SinricPro_RangeType;
extern enum Enum_LibState Lib_SinricProWrapper_State;

/* APIs */
extern void Lib_SinricProWrapper_Init(void);
extern void Lib_SinricProWrapper_Deinit(void);
extern void Lib_SinricProWrapper_Handle();
extern void Lib_SinricProWrapper_UpdateValue(enum Enum_SinricPro_RangeType, unsigned char);


#endif