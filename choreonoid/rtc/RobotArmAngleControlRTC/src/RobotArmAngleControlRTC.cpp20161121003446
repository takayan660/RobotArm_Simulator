// -*- C++ -*-
/*!
 * @file  RobotArmAngleControlRTC.cpp
 * @brief RobotArmAngleControlRTC
 * @date $Date$
 *
 * $Id$
 */

#include "RobotArmAngleControlRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* robotarmanglecontrolrtc_spec[] =
  {
    "implementation_id", "RobotArmAngleControlRTC",
    "type_name",         "RobotArmAngleControlRTC",
    "description",       "RobotArmAngleControlRTC",
    "version",           "1.0.0",
    "vendor",            "Takaharu Nakajima",
    "category",          "Generic",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
RobotArmAngleControlRTC::RobotArmAngleControlRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RobotArmAngleControlRTC::~RobotArmAngleControlRTC()
{
}



RTC::ReturnCode_t RobotArmAngleControlRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RobotArmAngleControlRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RobotArmAngleControlRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RobotArmAngleControlRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t RobotArmAngleControlRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RobotArmAngleControlRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RobotArmAngleControlRTC::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RobotArmAngleControlRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RobotArmAngleControlRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RobotArmAngleControlRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RobotArmAngleControlRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RobotArmAngleControlRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void RobotArmAngleControlRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(robotarmanglecontrolrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<RobotArmAngleControlRTC>,
                             RTC::Delete<RobotArmAngleControlRTC>);
  }
  
};


