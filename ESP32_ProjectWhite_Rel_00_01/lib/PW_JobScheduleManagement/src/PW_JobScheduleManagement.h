/*
  PW_JobScheduleManagement.cpp - Library for Management of controller's Job Scheduler.
  Created by Sumant Marathe, August 6, 2022.
  Released into the public domain.
*/

#ifndef PW_JOBSCHEDULEMANAGEMENT_H
#define PW_JOBSCHEDULEMANAGEMENT_H

#include <Arduino.h>
#include <Ticker.h>
#include "PW_PowerManagement.h"

class PW_JobScheduleManagement
{
    public:
        PW_JobScheduleManagement();
        void JobScheduler();
        void SetupCycle(unsigned long);
        void ScheduleJob(unsigned long);
        Ticker JobTicker;
        PW_PowerManagement PwrMgmt;

    private:
        unsigned long JobSchCycleTime;
        unsigned long JobSchCycleCnt; 
            
};

#endif