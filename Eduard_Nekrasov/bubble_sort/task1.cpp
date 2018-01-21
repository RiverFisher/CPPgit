#include "task1.h"
#include <iostream>
#include "assert.h"
#include "test.h"

using namespace std;

void Eduard_Nekrasov::initTask1(){

    cout << "Start test 1" << endl;
    assert(test1());
    cout << "Complete test 1" << endl;
    cout << "Start test 2" << endl;
    assert(test2());
    cout << "Complete test 2" << endl;
    cout << "Start test 3" << endl;
    assert(test3());
    cout << "Complete test 3" << endl;

}
