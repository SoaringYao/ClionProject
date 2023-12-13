cmake_minimum_required(VERSION 3.27)
project(SimHash)

set(CMAKE_CXX_STANDARD 17)

add_executable(SimHash
        main.cpp
        SimAsses.cpp
        SimAsses.h
        OpenHashing.cpp
        OpenHashing.h
        define.h
        system.cpp
        system.h)
