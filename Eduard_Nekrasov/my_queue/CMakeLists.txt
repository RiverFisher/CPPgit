cmake_minimum_required(VERSION 3.8)
project(my_queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        task2.h
        task2.cpp)

add_executable(my_queue ${SOURCE_FILES})