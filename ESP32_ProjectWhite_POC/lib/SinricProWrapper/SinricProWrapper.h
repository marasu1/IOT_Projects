/**
 * @file SinricProWrapper.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SINRICPROWRAPPER_H
#define SINRICPROWRAPPER_H


#include <Arduino.h>
#include "CommonDefs.h"


/* Sinric Pro Defines */
#define APP_KEY           "13d19ffd-0d04-458c-835a-71f8a7e6fa24"    // Should look like "de0bxxxx-1x3x-4x3x-ax2x-5dabxxxxxxxx"
#define APP_SECRET        "c1981d54-899a-441c-a7cb-d7f4b1378758-04d5e0f0-6acf-44e6-ac2e-c2f4526fc9d7"   // Should look like "5f36xxxx-x3x7-4x3x-xexe-e86724a9xxxx-4c4axxxx-3x3x-x5xe-x9x3-333d65xxxxxx"

#define SWITCH_DIGITAL_PIN_01   2
#define NUMBER_OF_DEVICES   5

enum DeviceType 
{
    SWITCH = 0,
    FAN,
    UNUSED,
    NumberOfDeviceTypes
};




/* APIs */
extern void SinricProWrapper_Handle();
extern void SinricProWrapper_Init(void);

typedef bool (*fptr_OnPowerState_cbk)(const String &deviceId, bool &state);
typedef bool (*fptr_OnRangeValue_cbk)(const String &deviceId, int& rangeValue);
typedef bool (*fptr_OnAdjustRangeValue_cbk)(const String &deviceId, int& rangeValueDelta);

typedef struct SinricProDevicesType
{
    enum DeviceType type;
    char id[50];
    fptr_OnPowerState_cbk Device_OnPowerState_Cbk;
    fptr_OnRangeValue_cbk Device_OnRangeValue_Cbk;
    fptr_OnAdjustRangeValue_cbk Device_OnAdjustRangeValue_Cbk;
} SinricProDevicesType;


extern bool SinricProWrapper_Dummy_OnPowerState_Cbk(const String &deviceId, bool &state);
extern bool SinricProWrapper_Dummy_OnRangeValue_Cbk(const String &deviceId, int& rangeValue);
extern bool SinricProWrapper_Dummy_OnAdjustRangeValue_Cbk(const String &deviceId, int& rangeValueDelta);

extern bool SinricProWrapper_Switch01_OnPowerState_Cbk(const String &deviceId, bool &state);

extern bool SinricProWrapper_Fan01_OnPowerState_Cbk(const String &deviceId, bool &state);
extern bool SinricProWrapper_Fan01_OnRangeValue_Cbk(const String &deviceId, int& rangeValue);
extern bool SinricProWrapper_Fan01_OnAdjustRangeValue_Cbk(const String &deviceId, int& rangeValueDelta);

#endif