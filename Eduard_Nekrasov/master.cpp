#include "master.h"
#include <iostream>
#include "bubble_sort/task1.h"
#include "my_queue/task2.h"

using namespace std;

int thread5() {
    cout << "Project was run!!!" << endl;

    cout << "Bubble sort was run" << endl;
    Eduard_Nekrasov::initTask1();
    cout << "Bubble sort was end" << endl;

    cout << "Queue was run" << endl;
    Eduard_Nekrasov::initTask2();
    cout << "Queue was end" << endl;
    return 0;
}
