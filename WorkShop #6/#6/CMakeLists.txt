cmake_minimum_required(VERSION 4.1)
project(_6)

set(CMAKE_CXX_STANDARD 26)

add_executable(_6 testDrive.cpp
        panel.cpp
        panel.h
        switch.cpp
        switch.h)
