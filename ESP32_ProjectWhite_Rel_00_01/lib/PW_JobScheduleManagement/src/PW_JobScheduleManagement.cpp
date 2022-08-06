/*
  PW_JobScheduleManagement.cpp - Library for Management of controller's Job Scheduler.
  Created by Sumant Marathe, August 6, 2022.
  Released into the public domain.
*/

#include <Arduino.h>
#include "PW_JobScheduleManagement.h"

PW_JobScheduleManagement *tempObj;

void Schedule()
{
    tempObj->JobScheduler();
}

PW_JobScheduleManagement::PW_JobScheduleManagement()
{
    tempObj = this;
    Serial.begin(115200);
    pinMode(2, OUTPUT);
}

void PW_JobScheduleManagement::JobScheduler()
{
    JobSchCycleCnt = JobSchCycleCnt + 1;
    if(0 == JobSchCycleCnt % (20/JobSchCycleTime))
    {
        PwrMgmt.MonitorPowerMode1();
    }
    
    if(0 == JobSchCycleCnt % (100/JobSchCycleTime))
    {
        PwrMgmt.MonitorPowerMode2();
    }

    if(0 == JobSchCycleCnt % (500/JobSchCycleTime))
    {
        Serial.print("Schm_Cnt = ");
        Serial.print(JobSchCycleCnt);
        Serial.println();
        Serial.print("PowerMode01Cnt = ");
        Serial.print(PwrMgmt.PowerMode01Cnt);
        Serial.println();
        Serial.print("PowerMode02Cnt = ");
        Serial.print(PwrMgmt.PowerMode02Cnt);
        Serial.println();
        Serial.println();
        digitalWrite(2, ~(digitalRead(2)));
    }
}

void PW_JobScheduleManagement::SetupCycle(unsigned long CycleTime)
{
    JobSchCycleTime = CycleTime;
    JobTicker.attach_ms(JobSchCycleTime, Schedule);
}