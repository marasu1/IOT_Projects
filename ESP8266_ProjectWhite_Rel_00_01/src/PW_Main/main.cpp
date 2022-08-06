#include <Arduino.h>
#include "PW_JobScheduleManagement.h"
#include "PW_PowerManagement.h"


PW_PowerManagement PwrMgmt;
PW_JobScheduleManagement JobSchMgmt;



void Scheduler()
{

}

void setup() 
{
    JobSchMgmt.SetupCycle(0.005);
    
}

void loop() 
{
  /* Empty Function */
}