cmake_minimum_required(VERSION 2.8.4)
project(two_four_tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Node.h
    TwoFourTree.c
    TwoFourTree.h
    TwoFourTreeDriver.c)

add_executable(two_four_tree ${SOURCE_FILES})