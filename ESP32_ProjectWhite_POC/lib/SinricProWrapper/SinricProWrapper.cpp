/**
 * @file SinricProWrapper.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "SinricPro.h"
#include "SinricProSwitch.h"
#include "SinricProFanUS.h"
#include "SinricProWrapper.h"
#include "Database.h"


const SinricProDevicesType SinricProDevices[NUMBER_OF_DEVICES] = 
{
    {
        SWITCH,
        "62ee4b3fda0cc6324369b6b2",
        SinricProWrapper_Switch01_OnPowerState_Cbk,
        SinricProWrapper_Dummy_OnRangeValue_Cbk,
        SinricProWrapper_Dummy_OnAdjustRangeValue_Cbk
    },
    {
        FAN,
        "63213c3336b44d06d4bae787",
        SinricProWrapper_Fan01_OnPowerState_Cbk,
        SinricProWrapper_Fan01_OnRangeValue_Cbk,
        SinricProWrapper_Fan01_OnAdjustRangeValue_Cbk
    },
    {
        UNUSED,
        "NA",
        SinricProWrapper_Dummy_OnPowerState_Cbk,
        SinricProWrapper_Dummy_OnRangeValue_Cbk,
        SinricProWrapper_Dummy_OnAdjustRangeValue_Cbk
    },
    {
        UNUSED,
        "NA",
        SinricProWrapper_Dummy_OnPowerState_Cbk,
        SinricProWrapper_Dummy_OnRangeValue_Cbk,
        SinricProWrapper_Dummy_OnAdjustRangeValue_Cbk
    },
    {
        UNUSED,
        "NA",
        SinricProWrapper_Dummy_OnPowerState_Cbk,
        SinricProWrapper_Dummy_OnRangeValue_Cbk,
        SinricProWrapper_Dummy_OnAdjustRangeValue_Cbk
    }
};


/**
 * @brief Wrapper API for SinricPro.handle 
 * 
 */
void SinricProWrapper_Handle(void)
{
    SinricPro.handle();
}

/**
 * @brief API for initialization of Sinric Pro
 * 
 */
void SinricProWrapper_Init(void)
{
    unsigned char deviceIndex = 0;

    for(deviceIndex = 0; deviceIndex < NUMBER_OF_DEVICES; deviceIndex++)
    {
        if(SinricProDevices[deviceIndex].type == SWITCH)
        {
            // add switch to SinricPro
            SinricProSwitch& mySwitch = SinricPro[SinricProDevices[deviceIndex].id];
        
            // set callback function to device
            mySwitch.onPowerState(SinricProDevices[deviceIndex].Device_OnPowerState_Cbk);
            
        }
        else if(SinricProDevices[deviceIndex].type == FAN)
        {
            // add fan to SinricPro
            SinricProFanUS &myFan = SinricPro[SinricProDevices[deviceIndex].id];

            // set callback function to device
            myFan.onPowerState(SinricProDevices[deviceIndex].Device_OnPowerState_Cbk);
            myFan.onRangeValue(SinricProDevices[deviceIndex].Device_OnRangeValue_Cbk);
            myFan.onAdjustRangeValue(SinricProDevices[deviceIndex].Device_OnAdjustRangeValue_Cbk);
        }
        else
        {
            /* Do nothing */
        }
        
    }

    // setup SinricPro
    SinricPro.onConnected([](){ Serial.printf("Connected to SinricPro\r\n"); }); 
    SinricPro.onDisconnected([](){ Serial.printf("Disconnected from SinricPro\r\n"); });
    
    //SinricPro.restoreDeviceStates(true); // Uncomment to restore the last known state from the server.
    SinricPro.begin(APP_KEY, APP_SECRET);
}

/**
 * @brief OnPowerState Callback for Device Switch 01
 * 
 * @param deviceId 
 * @param state 
 * @return true 
 * @return false 
 */
bool SinricProWrapper_Switch01_OnPowerState_Cbk(const String &deviceId, bool &state)
{
    Serial.printf("Device %s turned %s (via SinricPro) \r\n", deviceId.c_str(), state?"on":"off");
    
    DB_DeviceSwitch01_Status = state;

    DB_DigitalPinStatus[SWITCH_DIGITAL_PIN_01] = state;

    return true; // request handled properly
}

/**
 * @brief OnPowerState Callback for Device Fan 01
 * 
 * @param deviceId 
 * @param state 
 * @return true 
 * @return false 
 */
bool SinricProWrapper_Fan01_OnPowerState_Cbk(const String &deviceId, bool &state)
{
    Serial.printf("Device %s turned %s (via SinricPro) \r\n", deviceId.c_str(), state?"on":"off");
    
    DB_DeviceFan01_Status = state;

    return true; // request handled properly
}

/**
 * @brief OnRangeValue Callback for Device Fan 01
 * 
 * @param deviceId 
 * @param rangeValue 
 * @return true 
 * @return false 
 */
bool SinricProWrapper_Fan01_OnRangeValue_Cbk(const String &deviceId, int& rangeValue) 
{
    unsigned char fanValueInByte = 0;

    fanValueInByte = (unsigned char)rangeValue;

    DB_DeviceFan01_Value = fanValueInByte;
    Serial.printf("Fan speed changed to %d\r\n", DB_DeviceFan01_Value);
    return true;
}

/**
 * @brief _OnAdjustRangeValue Callback for Device Fan 01
 * 
 * @param deviceId 
 * @param rangeValueDelta 
 * @return true 
 * @return false 
 */
bool SinricProWrapper_Fan01_OnAdjustRangeValue_Cbk(const String &deviceId, int& rangeValueDelta) 
{
    unsigned char fanDeltaValueInByte = 0;

    fanDeltaValueInByte = (unsigned char)rangeValueDelta;
    
    DB_DeviceFan01_Value += fanDeltaValueInByte;
    Serial.printf("Fan speed changed about %i to %d\r\n", rangeValueDelta, DB_DeviceFan01_Value);
    
    /* pass back the new absolute fan speed through the input argument */
    rangeValueDelta = DB_DeviceFan01_Value;
    return true;
}


/**
 * @brief Dummy Callbacks
 * 
 * @param deviceId 
 * @param state 
 * @return true 
 * @return false 
 */
bool SinricProWrapper_Dummy_OnPowerState_Cbk(const String &deviceId, bool &state)
{
    /* Dummy Function */
    return true;
}

bool SinricProWrapper_Dummy_OnRangeValue_Cbk(const String &deviceId, int& rangeValue)
{
    /* Dummy Function */
    return true;
}

bool SinricProWrapper_Dummy_OnAdjustRangeValue_Cbk(const String &deviceId, int& rangeValueDelta)
{
    /* Dummy Function */
    return true;
}