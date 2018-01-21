#include "master.h"
#include <iostream>
#include "bubble_sort/task1.h"
#include "my_queue/task2.h"

using namespace std;

int thread5() {
    cout << "Project was run!!!" << endl;

    cout << "Bubble sort was run" << endl;
    Eduard_Nekrasov_bubble_sort();
    cout << "Bubble sort was end" << endl;

    cout << "Queue was run" << endl;
    Eduard_Nekrasov_Queue();
    cout << "Queue was end" << endl;
    return 0;
}
