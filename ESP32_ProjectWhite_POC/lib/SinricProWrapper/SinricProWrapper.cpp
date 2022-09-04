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

static boolean myPowerState = false;


/**
 * @brief local function for the event of power state change
 * 
 * @param deviceId 
 * @param state 
 * @return true 
 * @return false 
 */
static bool onPowerState(const String &deviceId, bool &state) 
{
    Serial.printf("Device %s turned %s (via SinricPro) \r\n", deviceId.c_str(), state?"on":"off");
    
    myPowerState = state;
    
    digitalWrite(BUILTIN_LED_PIN, myPowerState?LOW:HIGH);
    return true; // request handled properly
}

/**
 * @brief Wrapper API for SinricPro.handle 
 * 
 */
void SinricProWrapper_handle(void)
{
    SinricPro.handle();
}

/**
 * @brief API for initialization of Sinric Pro
 * 
 */
void SinricProWrapper_Init(void)
{
    myPowerState = LOW;

    // add device to SinricPro
    SinricProSwitch& mySwitch = SinricPro[SWITCH_ID];

    // set callback function to device
    mySwitch.onPowerState(onPowerState);

    // setup SinricPro
    SinricPro.onConnected([](){ Serial.printf("Connected to SinricPro\r\n"); }); 
    SinricPro.onDisconnected([](){ Serial.printf("Disconnected from SinricPro\r\n"); });
    
    //SinricPro.restoreDeviceStates(true); // Uncomment to restore the last known state from the server.
    SinricPro.begin(APP_KEY, APP_SECRET);
}