cmake_minimum_required(VERSION 2.8.4)
project(bloom_filter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Bloom.c
    Bloom.h
    Driver.c
    PMurHash.c
    PMurHash.h)

add_executable(bloom_filter ${SOURCE_FILES})