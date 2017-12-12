#include <iostream>
#include "Alexander_Melnik/master.h"
#include "Alexey_Remigailo/master.h"
#include "Dmitry_Fedorenko/master.h"
#include "Dmitry_Zvezdetskiy/master.h"
#include "Eduard_Nekrasov/master.h"
#include "Marina_Gribacheva/master.h"
#include "Nikita_Larichev/master.h"
#include "Vitaly_Vesyolko/master.h"

using namespace std;

void run();

int main() {
    /**
     * Run threads of every group participant
     */
    run();

    return 0;
}

void run() {
    thread1();
    thread2();
    thread3();
    thread4();
    thread5();
    thread6();
    thread7();
    thread8();
}
