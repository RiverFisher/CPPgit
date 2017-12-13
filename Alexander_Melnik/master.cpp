#include "master.h"
#include <iostream>

int thread1() {
    std::cout << "Thread 1 was run." << std::endl;
    std::cout << "Alexander Melnik" << std::endl;
    initTask8();

    return 0;
}
