/**
 * @file CommunicationHandler.cpp
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "CommunicationHandler.h"


/* Global variables */


/**
 * @brief Initialize the Communication Handler
 * 
 */
void CommunicationHandler_Init(void)
{
    Serial.begin(SERIAL_COMM_BAUD_RATE);
}
