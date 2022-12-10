/**
 * @file Lib_WifiHandler.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LIB_WIFIHANDLER_H
#define LIB_WIFIHANDLER_H

#include <Arduino.h>
#include "Lib_CommonDefs.h"

/* Wifi Defines */
#define WIFI_SSID         "Marathe"    
#define WIFI_PASS         "7588105227"

extern enum Enum_LibState Lib_WifiHandler_State;

/* APIs */
extern void Lib_WifiHandler_Init(void);
extern void Lib_WifiHandler_Deinit(void);


#endif