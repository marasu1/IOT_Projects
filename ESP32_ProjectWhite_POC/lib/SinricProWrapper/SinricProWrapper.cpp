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
#include "SinricProWrapper.h"
#include "Database.h"


const SinricProDevicesType SinricProDevices[NUMBER_OF_DEVICES] = 
{
    {
        SWITCH,
        "62ee4b3fda0cc6324369b6b2",
        SinricProWrapper_Switch_Cbk_01
    },
    {
        UNUSED,
        "NA",
        SinricProWrapper_Dummy
    },
    {
        UNUSED,
        "NA",
        SinricProWrapper_Dummy
    },
    {
        UNUSED,
        "NA",
        SinricProWrapper_Dummy
    },
    {
        UNUSED,
        "NA",
        SinricProWrapper_Dummy
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
            // add device to SinricPro
            SinricProSwitch& mySwitch = SinricPro[SinricProDevices[deviceIndex].id];
        
            // set callback function to device
            mySwitch.onPowerState(SinricProDevices[deviceIndex].Device_Cbk);
            
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
 * @brief Callback for Device Swtich 01
 * 
 * @param deviceId 
 * @param state 
 * @return true 
 * @return false 
 */
bool SinricProWrapper_Switch_Cbk_01(const String &deviceId, bool &state)
{
    Serial.printf("Device %s turned %s (via SinricPro) \r\n", deviceId.c_str(), state?"on":"off");
    
    DB_DigitalPinStatus[SWITCH_DIGITAL_PIN_01] = state;

    return true; // request handled properly
}

/**
 * @brief Dummy Callback
 * 
 * @param deviceId 
 * @param state 
 * @return true 
 * @return false 
 */
bool SinricProWrapper_Dummy(const String &deviceId, bool &state)
{
    /* Dummy Function */
    return true;
}