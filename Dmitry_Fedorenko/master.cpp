#include "master.h"
#include <iostream>

#include "Task8/conventer.h"

int thread3() {
    std::cout << "Thread 3 was run." << std::endl;
    std::cout << "Dmitry Fedorenko" << std::endl;
    Dmitry_Fedorenko::initTask8();

    return 0;
}
