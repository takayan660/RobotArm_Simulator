// -*- C++ -*-
/*!
 * @file  PDController.cpp
 * @brief Robot Controller component 2
 * @date $Date$
 *
 * $Id$
 */

#include "PDController.h"
#include <cnoid/BodyMotion>
#include <cnoid/ExecutablePath>
#include <cnoid/FileUtil>

using namespace std;
using namespace cnoid;

#define PI 3.1415926


// Module specification
// <rtc-template block="module_spec">
static const char* pdcontroller_spec[] =
{
    "implementation_id", "PDController",
    "type_name",         "PDController",
    "description",       "PD Controller component 2",
    "version",           "1.0.0",
    "vendor",            "AIST",
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
PDController::PDController(RTC::Manager* manager)
    // <rtc-template block="initializer">
    : RTC::DataFlowComponentBase(manager),
    m_angleIn("q", m_angle),
    m_torqueOut("u", m_torque),
    dt(0.001),
    dq_old(0.0)

      // </rtc-template>
{
}

/*!
 * @brief destructor
 */
PDController::~PDController()
{
}

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

void PDController::ReadGain(size_t numJoints,std::vector<double> &pgain,std::vector<double> &dgain)
{
    FILE *PDGain;
    float temp_pgain,temp_dgain;
    char joint_name[20];
    PDGain = fopen("/usr/lib/choreonoid-1.6/rtc/pdgain.txt","r");

    pgain.clear(); dgain.clear();

    pgain.resize(numJoints);
    dgain.resize(numJoints);
    angleRef.resize(numJoints);
    q_old.resize(numJoints);
    q_old_ref.resize(numJoints);
    m_torque.data.length(numJoints);

    int i=0;
    while(fscanf(PDGain,"%f %f",&temp_pgain,&temp_dgain) != EOF)
    {
        pgain[i] = temp_pgain;
        dgain[i] = temp_dgain;
        i++;
    }
}



RTC::ReturnCode_t PDController::onInitialize()
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
   RTC::ReturnCode_t PDController::onFinalize()
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t PDController::onStartup(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t PDController::onShutdown(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */


RTC::ReturnCode_t PDController::onActivated(RTC::UniqueId ec_id)
{
    if(m_angleIn.isNew()){
        m_angleIn.read();
        ReadGain(m_angle.data.length(),pgain,dgain);
    }

    for(size_t i=0;i<m_angle.data.length();i++){
        angleRef[i] = q_old[i] = q_old_ref[i] = m_angle.data[i];
    }

    for(int i=0; i<5; i++){
        cout<<"Link "<< i+1 <<" angle = ";
        cin >> LinkAngle[i];
    }

    return RTC::RTC_OK;
}


RTC::ReturnCode_t PDController::onDeactivated(RTC::UniqueId ec_id)
{
    cout<<"Deactivated"<<endl;

    return RTC::RTC_OK;
}


RTC::ReturnCode_t PDController::onExecute(RTC::UniqueId ec_id)
{
    if(m_angleIn.isNew()){
        m_angleIn.read();
    }

    for(size_t i=0; i < m_angle.data.length(); i++){
        double q_ref = angleRef[i];
        double q = m_angle.data[i];
        double dq_ref = (q_ref - q_old_ref[i]) / dt;
        double dq = (q - q_old[i]) / dt;
        m_torque.data[i] = (deg2rad(LinkAngle[i]) - q) * pgain[i] + (dq_ref - dq) * dgain[i];
        q_old[i] = q;
    }
    q_old_ref = angleRef;
    m_torqueOut.write();

    return RTC::RTC_OK;
}

/*
   RTC::ReturnCode_t PDController::onAborting(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t PDController::onError(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t PDController::onReset(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t PDController::onStateUpdate(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */

/*
   RTC::ReturnCode_t PDController::onRateChanged(RTC::UniqueId ec_id)
   {
   return RTC::RTC_OK;
   }
   */



extern "C"
{

    void PDControllerInit(RTC::Manager* manager)
    {
        coil::Properties profile(pdcontroller_spec);
        manager->registerFactory(profile,
                RTC::Create<PDController>,
                RTC::Delete<PDController>);
    }

};


