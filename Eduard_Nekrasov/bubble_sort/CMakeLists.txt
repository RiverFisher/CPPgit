cmake_minimum_required(VERSION 3.8)
project(buble_sort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        task1.cpp
        task1.h)
add_executable(buble_sort ${SOURCE_FILES})