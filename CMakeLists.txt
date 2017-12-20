cmake_minimum_required(VERSION 3.8)
project(CPPgit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Vitaly_Vesyolko/ArrayOperations/null.cpp
        Vitaly_Vesyolko/ArrayOperations/fill.cpp
        Vitaly_Vesyolko/master.cpp
        Alexander_Melnik/master.cpp
        Alexey_Remigailo/master.cpp
        Dmitry_Fedorenko/master.cpp
        Dmitry_Zvezdetskiy/master.cpp
        Eduard_Nekrasov/master.cpp
        Marina_Gribacheva/master.cpp
        Nikita_Larichev/master.cpp
)

add_executable(CPPgit ${SOURCE_FILES})