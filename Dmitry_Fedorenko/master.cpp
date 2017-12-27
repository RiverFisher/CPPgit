#include "master.h"
#include <iostream>

#include "Task8/conventer.h"
#include "Task4/same_elements.h"

int thread3() {
    std::cout << "Thread 3 was run." << std::endl;
    std::cout << "Dmitry Fedorenko" << std::endl;
    Dmitry_Fedorenko::initTask8();
    Dmitry_Fedorenko::initTask4();

    return 0;
}
