/**
 * @file InterruptHandler.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INTERRUPTHANDLER_H
#define TIMERHINTERRUPTHANDLER_HANDLER_H

#include <Arduino.h>
#include "CommonDefs.h"

/* APIs */
extern boolean InterruptHandler_AttachTimerInterrupt(unsigned int);
extern boolean InterruptHandler_AttachDigitalPinInterrupt(unsigned int);




#endif