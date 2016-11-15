# RobotArmAngleControlRTC CMake config file
#
# This file sets the following variables:
# RobotArmAngleControlRTC_FOUND - Always TRUE.
# RobotArmAngleControlRTC_INCLUDE_DIRS - Directories containing the RobotArmAngleControlRTC include files.
# RobotArmAngleControlRTC_IDL_DIRS - Directories containing the RobotArmAngleControlRTC IDL files.
# RobotArmAngleControlRTC_LIBRARIES - Libraries needed to use RobotArmAngleControlRTC.
# RobotArmAngleControlRTC_DEFINITIONS - Compiler flags for RobotArmAngleControlRTC.
# RobotArmAngleControlRTC_VERSION - The version of RobotArmAngleControlRTC found.
# RobotArmAngleControlRTC_VERSION_MAJOR - The major version of RobotArmAngleControlRTC found.
# RobotArmAngleControlRTC_VERSION_MINOR - The minor version of RobotArmAngleControlRTC found.
# RobotArmAngleControlRTC_VERSION_REVISION - The revision version of RobotArmAngleControlRTC found.
# RobotArmAngleControlRTC_VERSION_CANDIDATE - The candidate version of RobotArmAngleControlRTC found.

message(STATUS "Found RobotArmAngleControlRTC-1.0.0")
set(RobotArmAngleControlRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(RobotArmAngleControlRTC_INCLUDE_DIRS
#    "/usr/local/include/robotarmanglecontrolrtc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(RobotArmAngleControlRTC_IDL_DIRS
#    "/usr/local/include/robotarmanglecontrolrtc-1/idl")
set(RobotArmAngleControlRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(RobotArmAngleControlRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(RobotArmAngleControlRTC_LIBRARIES
        "/usr/local/components/lib/librobotarmanglecontrolrtc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(RobotArmAngleControlRTC_LIBRARIES
        "/usr/local/components/lib/librobotarmanglecontrolrtc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(RobotArmAngleControlRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(RobotArmAngleControlRTC_VERSION 1.0.0)
set(RobotArmAngleControlRTC_VERSION_MAJOR 1)
set(RobotArmAngleControlRTC_VERSION_MINOR 0)
set(RobotArmAngleControlRTC_VERSION_REVISION 0)
set(RobotArmAngleControlRTC_VERSION_CANDIDATE )

