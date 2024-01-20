cmake_minimum_required(VERSION 3.27)
project(Assignment7_SetClassSimulation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment7_SetClassSimulation
        main.cpp
        IntegerSet.cpp
        IntegerSet.h)
