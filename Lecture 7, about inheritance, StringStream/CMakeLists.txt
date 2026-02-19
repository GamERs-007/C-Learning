cmake_minimum_required(VERSION 4.1)
project(class7 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(class7
        school.h
        testDrive.cpp)
