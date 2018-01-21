#include <string>
#include "null.h"

bool nullArrayOfNumbers(int *array) {
    for (int i = 0; i < 32; i++) {
        array[i] = 0;
    }
}

bool nullArrayOfStrings(std::string *array) {
    for (int i = 0; i < 32; i++) {
        array[i] = "";
    }
}