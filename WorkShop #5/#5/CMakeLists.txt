cmake_minimum_required(VERSION 4.1)
project(_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(_5
        Driver.cpp
        SizeOf.h
        Student.h
        TimeSort.h)
