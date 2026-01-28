cmake_minimum_required(VERSION 3.30)
project(source_code_for_tutorial)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(source_code_for_tutorial
    SimpleEncryption.h
    testDriver.cpp)
