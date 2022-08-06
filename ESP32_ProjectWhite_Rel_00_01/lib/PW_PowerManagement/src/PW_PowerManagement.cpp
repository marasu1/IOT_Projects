/*
  PW_PowerManagement.cpp - Library for Management of controller's power modes.
  Created by Sumant Marathe, August 6, 2022.
  Released into the public domain.
*/

#include <Arduino.h>
#include "PW_PowerManagement.h"

PW_PowerManagement::PW_PowerManagement()
{

}

void PW_PowerManagement::MonitorPowerMode1()
{
    PowerMode01Cnt = PowerMode01Cnt + 1;
}

void PW_PowerManagement::MonitorPowerMode2()
{
    PowerMode02Cnt = PowerMode02Cnt + 1;
}