/*
  PW_JobScheduleManagement.cpp - Library for Management of controller's Job Scheduler.
  Created by Sumant Marathe, August 6, 2022.
  Released into the public domain.
*/

#include <Arduino.h>
#include "PW_JobScheduleManagement.h"
#include "PW_PowerManagement.h"

PW_JobScheduleManagement *tempObj;

void Schedule()
{
    tempObj->JobScheduler();
}

PW_JobScheduleManagement::PW_JobScheduleManagement()
{
    tempObj = this;
}

void PW_JobScheduleManagement::JobScheduler()
{
    JobSchCycleCnt = JobSchCycleCnt + 1;

}

void PW_JobScheduleManagement::SetupCycle(unsigned long CycleTime)
{
    JobSchCycleTime = CycleTime;
    JobTicker.attach_ms(JobSchCycleTime, Schedule);
}