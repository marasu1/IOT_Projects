/*
  PW_JobScheduleManagement.cpp - Library for Management of controller's power modes.
  Created by Sumant Marathe, August 6, 2022.
  Released into the public domain.
*/

#include <Arduino.h>
#include <Ticker.h>
#include "PW_JobScheduleManagement.h"

Ticker JobTicker;

PW_JobScheduleManagement::PW_JobScheduleManagement()
{
   
}

void PW_JobScheduleManagement::JobScheduler()
{
    JobSchCycleCnt = JobSchCycleCnt + 1;
}

void PW_JobScheduleManagement::SetupCycle(double CycleTime)
{
    //JobTicker.attach(CycleTime, JobScheduler);
}