#include "bubble_s.h"
#include "test.h"
#include "task1.h"
#include <iostream>

using namespace std;


void bubble(int a[N_MAX])
{
    for(int i = 0; i < N_MAX; i++)
    {
        for(int j = 0; j <= i - 1;j++)
        {
            if (a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}