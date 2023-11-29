cmake_minimum_required(VERSION 3.26)
project(Josephus)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Josephus
        function.cpp
        function.h
        main.cpp)
