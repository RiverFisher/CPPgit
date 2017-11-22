cmake_minimum_required(VERSION 3.8)
project(CPPgit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp nullable.h nullable.cpp)
add_executable(CPPgit ${SOURCE_FILES})