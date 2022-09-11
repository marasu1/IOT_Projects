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
#define SWITCH_ID         "62ee4b3fda0cc6324369b6b2"      // Should look like "5dc1564130xxxxxxxxxxxxxx"

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

typedef bool (*fptr_cbk)(const String &deviceId, bool &state);

typedef struct SinricProDevicesType
{
    enum DeviceType type;
    char id[50];
    fptr_cbk Device_Cbk;
} SinricProDevicesType;

extern bool SinricProWrapper_Switch_Cbk_01(const String &deviceId, bool &state);
extern bool SinricProWrapper_Dummy(const String &deviceId, bool &state);

#endif