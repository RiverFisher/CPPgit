cmake_minimum_required(VERSION 3.8)
project(CPPgit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp null.h null.cpp fill.cpp fill.h)
add_executable(CPPgit ${SOURCE_FILES})