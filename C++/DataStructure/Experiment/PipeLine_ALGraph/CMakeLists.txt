cmake_minimum_required(VERSION 3.26)
project(PipeLine_ALGraph)

set(CMAKE_CXX_STANDARD 17)

add_executable(PipeLine_ALGraph
        main.cpp
        system.cpp
        system.h
        Search.cpp
        Search.h
        define.h
        ALGraph.cpp
        ALGraph.h)
