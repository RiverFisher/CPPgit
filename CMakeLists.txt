cmake_minimum_required(VERSION 3.8)
project(CPPgit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES 
        main.cpp
        Vitaly_Vesyolko/ArrayOperations/null.h
        Vitaly_Vesyolko/ArrayOperations/null.cpp
        Vitaly_Vesyolko/ArrayOperations/fill.cpp
        Vitaly_Vesyolko/ArrayOperations/fill.h
        Vitaly_Vesyolko/master.cpp
        Vitaly_Vesyolko/master.h
        Alexander_Melnik/master.cpp
        Alexander_Melnik/master.h
        Alexey_Remigailo/master.cpp
        Alexey_Remigailo/master.h
        Dmitry_Fedorenko/master.cpp
        Dmitry_Fedorenko/master.h
        Dmitry_Zvezdetskiy/master.cpp
        Dmitry_Zvezdetskiy/master.h
        Eduard_Nekrasov/master.cpp
        Eduard_Nekrasov/master.h
        Marina_Gribacheva/master.cpp
        Marina_Gribacheva/master.h
        Nikita_Larichev/master.cpp
        Nikita_Larichev/master.h
)

add_executable(CPPgit ${SOURCE_FILES})