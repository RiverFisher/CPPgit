cmake_minimum_required(VERSION 3.8)
project(buble_sort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp bubble_sort.cpp bubble_sort.h tests.cpp)
add_executable(buble_sort ${SOURCE_FILES})