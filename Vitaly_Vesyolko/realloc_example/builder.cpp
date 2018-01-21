#include "builder.h"
#include <cstdlib>
#include <cstdio>
#include "malloc.h"
#include <iostream>

void reallocDemonstration() {
    char *array = "abcdefghijklmnopqrstuvwxyz";

    char *temp = (char *) malloc(15);

    for (int i = 0; i < 15; i++) {
        temp[i] = array[i];
    }

    std::cout << temp << std::endl;

    temp = (char*) realloc(temp, 4 * sizeof(char));

    for (int i = 15; i < 19; i++) {
        temp[i] = array[i];
    }

    std::cout << temp << std::endl;
}
