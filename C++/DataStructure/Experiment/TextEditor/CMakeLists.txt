cmake_minimum_required(VERSION 3.26)
project(TextEditor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TextEditor
        grep.cpp
        grep.h
        main.cpp
        test.txt)
