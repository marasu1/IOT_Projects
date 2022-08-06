#include <Arduino.h>
#include "PW_JobScheduleManagement.h"

PW_JobScheduleManagement JobSchMgmt;

void setup() 
{
    JobSchMgmt.SetupCycle(5);
}

void loop() 
{
  /* Empty Function */
}