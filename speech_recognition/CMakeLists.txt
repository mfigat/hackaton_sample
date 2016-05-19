cmake_minimum_required (VERSION 2.8)
project (speech_recognition)

find_package(Rapp REQUIRED)
find_package(RappRobots REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${Rapp_DIR})
include(RappMacros)

setup_rapp()

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=gnu++11 -Wall -static-libstdc++ -m32")


create_rapp(
    NAME speech_recognition
    SRCS main.cpp
)
