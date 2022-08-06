/*
  PW_PowerManagement.h - Library for Management of controller's power modes.
  Created by Sumant Marathe, August 6, 2022.
  Released into the public domain.
*/

#ifndef PW_POWERMANAGEMENT_H
#define PW_POWERMANAGEMENT_H

#include <Arduino.h>

class PW_PowerManagement
{
  public:
    PW_PowerManagement();
    void MonitorPowerMode1();
    void MonitorPowerMode2();
    unsigned long PowerMode01Cnt;
    unsigned long PowerMode02Cnt;
    
  private:

};

#endif