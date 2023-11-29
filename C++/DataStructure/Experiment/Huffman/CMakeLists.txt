cmake_minimum_required(VERSION 3.26)
project(Huffman)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Huffman
        "word_read.cpp"
        "word_read.h"
        SqStack.cpp
        SqStack.h
        function.cpp
        function.h
        huffman.cpp
        huffman.h
        main.cpp
        article.txt
        word.txt
        ToBeTran.txt
        TextFile.txt
        CodeFile.txt)