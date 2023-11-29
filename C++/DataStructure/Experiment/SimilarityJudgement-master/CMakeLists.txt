cmake_minimum_required(VERSION 3.26)
project(SimilarityJudgement_master C)

set(CMAKE_C_STANDARD 11)

include_directories(Include)

add_executable(SimilarityJudgement_master
        Include/Hash.h
        Include/Trie.h
        MainTest.c)
