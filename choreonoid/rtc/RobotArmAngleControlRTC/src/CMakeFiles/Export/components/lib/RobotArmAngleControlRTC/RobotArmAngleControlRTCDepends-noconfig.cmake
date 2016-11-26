#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "RobotArmAngleControlRTC" for configuration ""
set_property(TARGET RobotArmAngleControlRTC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(RobotArmAngleControlRTC PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil;CnoidBody;CnoidBodyPlugin;CnoidUtil;CnoidBase;QtOpenGL;QtGui;QtCore;boost_system;boost_filesystem"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/RobotArmAngleControlRTC.so"
  IMPORTED_SONAME_NOCONFIG "RobotArmAngleControlRTC.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS RobotArmAngleControlRTC )
list(APPEND _IMPORT_CHECK_FILES_FOR_RobotArmAngleControlRTC "${_IMPORT_PREFIX}/components/lib/RobotArmAngleControlRTC.so" )

# Import target "RobotArmAngleControlRTCComp" for configuration ""
set_property(TARGET RobotArmAngleControlRTCComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(RobotArmAngleControlRTCComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/RobotArmAngleControlRTCComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS RobotArmAngleControlRTCComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_RobotArmAngleControlRTCComp "${_IMPORT_PREFIX}/components/bin/RobotArmAngleControlRTCComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
