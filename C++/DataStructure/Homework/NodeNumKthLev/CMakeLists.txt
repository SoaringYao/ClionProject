cmake_minimum_required(VERSION 3.26)
project(NodeLevK)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(NodeLevK
        BinaryTree.cpp
        BinaryTree.h
        main.cpp)
