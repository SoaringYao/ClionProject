cmake_minimum_required(VERSION 3.26)
project(CS_Function)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS_Function
        function.cpp
        function.h
        main.cpp
        SqStack.cpp
        SqStack.h)
