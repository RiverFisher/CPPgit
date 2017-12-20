#include "master.h"
#include <iostream>

#include "Task8/builder.h"
#include "Task9/builder.h"

int thread1() {
    std::cout << "Thread 1 was run." << std::endl;
    std::cout << "Alexander Melnik" << std::endl;
    initTask8();
    initTask9();

    return 0;
}
