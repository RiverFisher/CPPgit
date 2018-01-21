#include "task1.h"
#include <iostream>
#include "bubble_sort.h"
#include "assert.h"

using namespace std;

int Eduard_Nekrasov_bubble_sort() {

    cout << "Start test 1" << endl;
    assert(test1());
    cout << "Complete test 1" << endl;
    cout << "Start test 2" << endl;
    assert(test2());
    cout << "Complete test 2" << endl;
    cout << "Start test 3" << endl;
    assert(test3());
    cout << "Complete test 3" << endl;

    return 0;

}
