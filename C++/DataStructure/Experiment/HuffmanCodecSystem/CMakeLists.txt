cmake_minimum_required(VERSION 3.26)
project(HuffmanCodecSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(HuffmanCodecSystem main.cpp
        HuffmanCodec.h
        HuffmanCodec.cpp
        System.cpp
        System.h
        define.h
        SqStack.cpp
        SqStack.h
)
