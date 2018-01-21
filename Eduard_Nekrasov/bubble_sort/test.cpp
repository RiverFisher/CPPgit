#include "test.h"
#include <iostream>
#include "bubble_s.h"
#include "task1.h"

using namespace std;

bool test1(){

    int a1[N_MAX] = {};
    int a2[N_MAX] = {};

    bool error = false;

    bubble(a1);

    for (int i = 0; i < N_MAX; i++)
    {
        if ( a1[i] != a2[i] ) {
            error = true;
            return !error;
        }
    }

    return !error;
}

bool test2(){

    int a1[N_MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[N_MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    bool error = false;

    bubble(a1);

    for (int i = 0; i < N_MAX; i++)
    {
        if ( a1[i] != a2[i] ) {
            error = true;
            return !error;
        }
    }

    return !error;
}

bool test3(){

    int a1[N_MAX] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int a2[N_MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    bool error = false;

    bubble(a1);

    for (int i = 0; i < N_MAX; i++)
    {
        if ( a1[i] != a2[i] ) {
            error = true;
            return !error;
        }
    }

    return !error;

}