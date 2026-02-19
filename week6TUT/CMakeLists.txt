cmake_minimum_required(VERSION 4.1)
project(week6TUT)

set(CMAKE_CXX_STANDARD 26)

add_executable(week6TUT main.cpp
        Employee.h
        Employee.cpp
        FullTimeEmployee.h
        FullTimeEmployee.cpp
        PartTimeEmployee.h
        PartTimeEmployee.cpp)
