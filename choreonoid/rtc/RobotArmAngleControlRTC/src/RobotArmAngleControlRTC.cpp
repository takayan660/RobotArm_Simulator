// -*- C++ -*-
/*!
 * @file  RobotArmAngleControlRTC.cpp
 * @brief RobotArmAngleControlRTC
 * @date $Date$
 *
 * $Id$
 */

#include "RobotArmAngleControlRTC.h"
#include <iostream>
#include <cnoid/BodyMotion>
#include <cnoid/ExecutablePath>
#include <cnoid/FileUtil>

using namespace std;
using namespace cnoid;

namespace {

    static const double pgain[] = {
        50000.0, 30000.0, 30000.0, 30000.0,
    };

    static const double dgain[] = {
        100.0, 100.0, 100.0, 100.0,
    };
};

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
  : RTC::DataFlowComponentBase(manager),
    m_angleIn("q", m_angle),
    m_torqueOut("u", m_torque)

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
  addInPort("q", m_angleIn);
  
  // Set OutPort buffer
  addOutPort("u", m_torqueOut);
  
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
    if(!qseq){
        string filename = getNativePathString(
                boost::filesystem::path(shareDirectory())
                / "motion" / "RobotPattern.yaml");

        BodyMotion motion;

        if(!motion.loadStandardYAMLformat(filename)){
            cout << motion.seqMessage() << endl;
            return RTC::RTC_ERROR;
        }
        qseq = motion.jointPosSeq();
        if(qseq->numFrames() == 0){
            cout << "Empty motion data." << endl;
            return RTC::RTC_ERROR;
        }
        q0.resize(qseq->numParts());
        timeStep_ = qseq->getTimeStep();
    }

    m_torque.data.length(qseq->numParts());

    if(m_angleIn.isNew()){
        m_angleIn.read();
    }
    for(int i=0; i < qseq->numParts(); ++i){
        q0[i] = m_angle.data[i];
    }
    oldFrame = qseq->frame(0);
    currentFrame = 0;

    return RTC::RTC_OK;
}


RTC::ReturnCode_t RobotArmAngleControlRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RobotArmAngleControlRTC::onExecute(RTC::UniqueId ec_id)
{
    if(m_angleIn.isNew()){
        m_angleIn.read();
    }

    MultiValueSeq::Frame frame;

    if(currentFrame > qseq->numFrames()){
        frame = oldFrame;
    }else{
        frame = qseq->frame(currentFrame++);
    }

    for(int i=0; i < frame.size(); i++){
        double q_ref = frame[i];
        double q = m_angle.data[i];
        double dq_ref = (q_ref - oldFrame[i]) / timeStep_;
        double dq = (q - q0[i]) / timeStep_;
        m_torque.data[i] = (q_ref - q) * pgain[i]/100.0 + (dq_ref - dq) * dgain[i]/100.0;
        q0[i] = q;
    }
    oldFrame = frame;

    m_torqueOut.write();

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


