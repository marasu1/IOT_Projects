/**
 * @file main.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>
#include <Ticker.h>
#include <WiFi.h>

#include "SinricPro.h"
#include "SinricProSwitch.h"

#include "PW_CommonDefs.h"

Ticker JobTicker;
bool myPowerState = false;

void JobScheduler()
{
    SinricPro.handle();
}

bool onPowerState(const String &deviceId, bool &state) 
{
  Serial.printf("Device %s turned %s (via SinricPro) \r\n", deviceId.c_str(), state?"on":"off");
  myPowerState = state;
  digitalWrite(BUILTIN_LED_PIN, myPowerState?LOW:HIGH);
  return true; // request handled properly
}

void setupWiFi() 
{
    Serial.printf("\r\n[Wifi]: Connecting");
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) 
    {
        Serial.printf(".");
        delay(250);
    }
  
    Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
}

void setupSinricPro() 
{
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

void setup() 
{
    /**
     * @brief Init Project
     * 
     */

    Serial.begin(BAUD_RATE);
    myPowerState = LOW;

    /* Initialize GPIO pins */
    pinMode(BUILTIN_LED_PIN, OUTPUT);

    /* Setup Wifi */
    setupWiFi();

    /* Setup Sinric Pro */
    setupSinricPro();


    JobTicker.attach(PW_SCHEDULE_CYCLE_TIME, JobScheduler);
}

void loop()
{

}
