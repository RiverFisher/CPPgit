#include "master.h"
#include <iostream>
#include "bubble_sort/task1.h"
#include "my_queue/task2.h"

using namespace std;

int fact(int k)
{
    int fac = 1;
    for (int i = k;i>0;i--)
    {
        fac = fac * i;
    }
    return fac;
}
int thread5() {
    cout << "Project was run!!!" << endl;

    cout << "Bubble sort was run" << endl;
    Eduard_Nekrasov::initTask1();
    cout << "Bubble sort was end" << endl;

    cout << "Queue was run" << endl;
    Eduard_Nekrasov::initTask2();
    cout << "Queue was end" << endl;
    cout << fact(5) << endl;
    return 0;
}
