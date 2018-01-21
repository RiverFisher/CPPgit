cmake_minimum_required(VERSION 3.8)
project(CPPgit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp

        Alexander_Melnik/master.cpp
        Alexander_Melnik/Task8/builder.cpp
        Alexander_Melnik/Task9/builder.cpp

        Alexey_Remigailo/master.cpp

        Dmitry_Fedorenko/master.cpp
        Dmitry_Fedorenko/Task8/converter.cpp
        Dmitry_Fedorenko/Task4/same_elements.cpp

        Dmitry_Zvezdetskiy/master.cpp

        Eduard_Nekrasov/master.cpp

        Marina_Gribacheva/master.cpp

        Nikita_Larichev/master.cpp Eduard_Nekrasov/bubble_sort/task1.h Eduard_Nekrasov/bubble_sort/task1.cpp Eduard_Nekrasov/my_queue/task2.cpp Eduard_Nekrasov/my_queue/task2.h Eduard_Nekrasov/bubble_sort/test.cpp Eduard_Nekrasov/bubble_sort/test.h Eduard_Nekrasov/bubble_sort/bubble_s.cpp Eduard_Nekrasov/bubble_sort/bubble_s.h)

add_executable(CPPgit ${SOURCE_FILES})