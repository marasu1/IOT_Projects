/**
 * @file WifiHandler.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <WiFi.h>
#include "WifiHandler.h"
#include "CommunicationHandler.h"

/**
 * @brief API for initizaliztion of Wifi Handler
 * 
 */
void WifiHandler_Init()
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