/**
 * @file Lib_SinricProWrapper.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Lib_SinricProWrapper.h"
#include "SinricPro.h"
#include "WaterLevelSensor.h"


static bool onRangeValue(const String &deviceId, const String& instance, int &rangeValue);
static bool onAdjustRangeValue(const String &deviceId, const String& instance, int &valueDelta);


enum Enum_LibState Lib_SinricProWrapper_State = UNINIT;
WaterLevelSensor &waterLevelSensor = SinricPro[DEVICE_ID];


/*************
 * Variables *
 ***********************************************
 * Global variables to store the device states *
 ***********************************************/

// RangeController
std::map<String, int> globalRangeValues;




/**
 * @brief API for initialization of Sinric Pro
 * 
 */
void Lib_SinricProWrapper_Init(void)
{
    // RangeController
    waterLevelSensor.onRangeValue(SINRICPRO_WATER_LEVEL_RANGE, onRangeValue);
    waterLevelSensor.onAdjustRangeValue(SINRICPRO_WATER_LEVEL_RANGE, onAdjustRangeValue);
    waterLevelSensor.onRangeValue(SINRICPRO_BATTERY_LEVEL_RANGE, onRangeValue);
    waterLevelSensor.onAdjustRangeValue(SINRICPRO_BATTERY_LEVEL_RANGE, onAdjustRangeValue);


    SinricPro.onConnected([]{ Serial.printf("[SinricPro]: Connected\r\n"); });
    SinricPro.onDisconnected([]{ Serial.printf("[SinricPro]: Disconnected\r\n"); });
    SinricPro.begin(APP_KEY, APP_SECRET);

    Lib_SinricProWrapper_State = INIT;
}


/**
 * 
 * @brief API for de-initializing Sinric Pro
 * 
 */
void Lib_SinricProWrapper_Deinit(void)
{


    Lib_SinricProWrapper_State = DEINIT;
}


/**
 * @brief Wrapper API for SinricPro.handle 
 * 
 */
void Lib_SinricProWrapper_Handle(void)
{
    if(INIT == Lib_SinricProWrapper_State)
    {
        SinricPro.handle();
    }
    else
    {
        /* Do nothing */
    }
}


/*************
 * Callbacks *
 *************/

// RangeController
static bool onRangeValue(const String &deviceId, const String& instance, int &rangeValue) 
{
  Serial.printf("[Device: %s]: Value for \"%s\" changed to %d\r\n", deviceId.c_str(), instance.c_str(), rangeValue);
  globalRangeValues[instance] = rangeValue;
  return true;
}

static bool onAdjustRangeValue(const String &deviceId, const String& instance, int &valueDelta) 
{
  globalRangeValues[instance] += valueDelta;
  Serial.printf("[Device: %s]: Value for \"%s\" changed about %d to %d\r\n", deviceId.c_str(), instance.c_str(), valueDelta, globalRangeValues[instance]);
  globalRangeValues[instance] = valueDelta;
  return true;
}


/**********
 * Events *
 *************************************************
 * Examples how to update the server status when *
 * you physically interact with your device or a *
 * sensor reading changes.                       *
 *************************************************/

// RangeController
void Lib_SinricProWrapper_UpdateValue(enum Enum_SinricPro_RangeType range, unsigned char valueInPercent) 
{
    switch (range)
    {
    case WATER_LEVEL:
        waterLevelSensor.sendRangeValueEvent(SINRICPRO_WATER_LEVEL_RANGE, valueInPercent);
        break;
    
    case BATTERY_LEVEL:
        waterLevelSensor.sendRangeValueEvent(SINRICPRO_BATTERY_LEVEL_RANGE, valueInPercent);
        break;

    default:
        break;
    }   
}