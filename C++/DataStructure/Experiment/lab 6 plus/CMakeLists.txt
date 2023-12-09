cmake_minimum_required(VERSION 3.27)
project(lab_6_plus)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_6_plus
        main.cpp
        stable.cpp
        stable.h)
