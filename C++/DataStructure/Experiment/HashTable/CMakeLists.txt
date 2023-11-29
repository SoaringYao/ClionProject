cmake_minimum_required(VERSION 3.26)
project(HashTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashTable main.cpp
        HashTable.cpp
        HashTable.h
        SimHash.cpp
        SimHash.h
        define.h)
