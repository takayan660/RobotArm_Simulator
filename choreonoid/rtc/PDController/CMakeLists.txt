cmake_minimum_required(VERSION 2.8)

project(PDController)

find_package(Boost COMPONENTS system thread filesystem)

include(FindPkgConfig)
pkg_check_modules(cnoid_plugin REQUIRED choreonoid-body-plugin)
pkg_check_modules(openrtm_aist REQUIRED openrtm-aist)

include_directories(
    ${openrtm_aist_INCLUDE_DIRS}
    ${cnoid_plugin_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    )

link_directories(
    ${openrtm_aist_LIBRARY_DIRS}
    ${cnoid_plugin_LIBRARY_DIRS}
    ${Boost_LIBRARY_DIRS}
    )

add_library(PDController SHARED PDController.cpp)
set_target_properties(PDController PROPERTIES PREFIX "")

set(target PDController)
target_link_libraries(PDController
    ${openrtm_aist_LIBRARIES}
    ${cnoid_plugin_LIBRARIES}
    ${Boost_LIBRARIES}
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

install(TARGETS PDController LIBRARY DESTINATION /usr/local/lib/choreonoid-1.7/rtc)
install(FILES pdgain.txt DESTINATION /usr/local/lib/choreonoid-1.7/rtc)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
