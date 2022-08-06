/*
  PW_JobScheduleManagement.h - Library for Management of controller's power modes.
  Created by Sumant Marathe, August 6, 2022.
  Released into the public domain.
*/

#ifndef PW_JOBSCHEDULEMANAGEMENT_H
#define PW_JOBSCHEDULEMANAGEMENT_H

#include <Arduino.h>


class PW_JobScheduleManagement
{
    public:
        PW_JobScheduleManagement();
        void SetupCycle(double);

    private:
        unsigned long JobSchCycleCnt; 
        void JobScheduler();
};

#endif