cmake_minimum_required(VERSION 4.1)
project(SRC_CODE)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SRC_CODE
        GPUNode.cpp
        GPUNode.h
        testDriver.cpp)
