#include <stdio.h>
#include <time.h>
#include <iostream>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i=0; i<n-1; i++)
    {
        swapped = false;
        for (j=0; j<n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    srand(time(0));
    bubbleSort(arr, n);
    std::cout << "Sorting time = " << clock()/1000.0 << std::endl;
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}