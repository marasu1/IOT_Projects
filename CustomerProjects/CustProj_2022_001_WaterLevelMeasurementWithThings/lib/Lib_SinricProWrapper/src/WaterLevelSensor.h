/**
 * @file WaterLevelSensor.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef _WATERLEVELSENSOR_H_
#define _WATERLEVELSENSOR_H_

#include <SinricProDevice.h>
#include <Capabilities/RangeController.h>

class WaterLevelSensor 
: public SinricProDevice
, public RangeController<WaterLevelSensor> {
  friend class RangeController<WaterLevelSensor>;
public:
  WaterLevelSensor(const String &deviceId) : SinricProDevice(deviceId, "WaterLevelSensor") {};
};

#endif