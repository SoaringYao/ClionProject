cmake_minimum_required(VERSION 3.27)
project(Merge_Linklist)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Merge_Linklist
        function.h
        main.cpp
        function.cpp)
