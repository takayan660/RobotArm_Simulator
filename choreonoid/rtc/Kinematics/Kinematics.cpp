// -*- C++ -*-
/*!
 * @file  Kinematics.cpp
 * @brief Kinematics Calculation
 * @date $Date$
 *
 * $Id$
 */

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "Kinematics.h"

using namespace std;
using namespace Eigen;

#define PI 3.1415926

double deg2rad(double degree)
{
    double radian = degree * PI / 180.0f;
    return radian;
}

double rad2deg(double radian)
{
    double degree = radian * 180.0f / PI;
    return degree;
}

double ForwardKinematics(double angle)
{
    return position;
}

double InvserseKinematics(double position)
{
    return angle;
}

double CalcJacobian(double angle)
{
    return Jacobian;
}

// Module specification
// <rtc-template block="module_spec">
static const char* kinematics_spec[] =
{
    "implementation_id", "Kinematics",
    "type_name",         "Kinematics",
    "description",       "Kinematics Calculation",
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
Kinematics::Kinematics(RTC::Manager* manager)
    // <rtc-template block="initializer">
    : RTC::DataFlowComponentBase(manager),
    m_angleIn("q", m_angle),
    m_positionIn("p", m_position),
    m_angle_outOut("q_out", m_angle_out),
    m_position_outOut("p_out", m_position_out)

      // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Kinematics::~Kinematics()
{
}



RTC::ReturnCode_t Kinematics::onInitialize()
{
    // Registration: InPort/OutPort/Service
    // <rtc-template block="registration">
    // Set InPort buffers
    addInPort("q", m_angleIn);
    addInPort("p", m_positionIn);

    // Set OutPort buffer
    addOutPort("q_out", m_angle_outOut);
    addOutPort("p_out", m_position_outOut);

    // Set service provider to Ports

    // Set service consumers to Ports

    // Set CORBA Service Ports

    // </rtc-template>

    // <rtc-template block="bind_config">
    // </rtc-template>

    return RTC::RTC_OK;
}

/*
   RTC::ReturnCode_t Kinematics::onFinalize()
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t Kinematics::onStartup(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t Kinematics::onShutdown(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t Kinematics::onActivated(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t Kinematics::onDeactivated(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */


RTC::ReturnCode_t Kinematics::onExecute(RTC::UniqueId ec_id)
{

    return RTC::RTC_OK;
}

/*
   RTC::ReturnCode_t Kinematics::onAborting(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t Kinematics::onError(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t Kinematics::onReset(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t Kinematics::onStateUpdate(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t Kinematics::onRateChanged(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */



extern "C"
{

    void KinematicsInit(RTC::Manager* manager)
    {
        coil::Properties profile(kinematics_spec);
        manager->registerFactory(profile,
                RTC::Create<Kinematics>,
                RTC::Delete<Kinematics>);
    }

};


