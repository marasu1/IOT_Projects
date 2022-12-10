/**
 * @file Lib_WifiHandler.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <ESP8266WiFi.h>
#include "Lib_WifiHandler.h"

enum Enum_LibState Lib_WifiHandler_State = UNINIT;

/**
 * @brief API for initizaliztion of Wifi Handler
 * 
 */
void Lib_WifiHandler_Init()
{
    Serial.printf("\r\n[Wifi]: Connecting");
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) 
    {
        Serial.printf(".");
        delay(250);
    }
  
    Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
    
    Lib_WifiHandler_State = INIT;
}

/**
 * @brief API for de-initializing the Wifi Handler
 * 
 */
void Lib_WifiHandler_Deinit()
{


    Lib_WifiHandler_State = DEINIT;
}