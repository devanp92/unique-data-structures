cmake_minimum_required(VERSION 2.8.4)
project(data_structs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bloom_filter/Bloom.c
    bloom_filter/Bloom.h
    bloom_filter/Driver.c
    bloom_filter/PMurHash.c
    bloom_filter/PMurHash.h
    doubly_linked_list/LinkedList.c
    doubly_linked_list/LinkedList.h
    doubly_linked_list/Node.h
    merkle_tree/Merkle.h
    merkle_tree/Node.h
    merkle_tree/sha1.c
    queap/LinkedList.c
    queap/LinkedList.h
    queap/LinkedListDriver.c
    queap/Node.h
    queap/Queap.h
    queap/TwoFourTree.c
    queap/TwoFourTree.h
    queap/TwoFourTreeDriver.c
    trie/Driver.c
    trie/Node.h
    trie/Trie.c
    trie/Trie.h
    two_four_tree/Node.h
    two_four_tree/TwoFourTree.c
    two_four_tree/TwoFourTree.h
    two_four_tree/TwoFourTreeDriver.c)

add_executable(data_structs ${SOURCE_FILES})