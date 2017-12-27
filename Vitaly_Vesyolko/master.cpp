#include "master.h"
#include <iostream>
#include <cstring>
#include "ArrayOperations/null.h"
#include "ArrayOperations/fill.h"
#include "realloc_example/builder.h"

int thread8() {
    std::cout << "Thread 8 was run." << std::endl;

    int     *arrayOfIntegers = new int[32];
    std::string  *arrayOfStrings = new std::string[32];

    /**
     * Вызов функции time() возвращает системное время.
     * Благодаря тому, что вызов программы происходит в разный момент времени,
     * каждый раз числа будут генерироваться иначе, чем в предыдущих запусках программы.
     */
    srand(time(NULL));

    fillArrayOfIntegers(arrayOfIntegers);
    fillArrayOfStrings(arrayOfStrings);

    for (int i = 0; i < 32; i++) {
        std::cout << arrayOfIntegers[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 32; i++) {
        std::cout << arrayOfStrings[i] << " ";
    }
    std::cout << std::endl;

    nullArrayOfNumbers(arrayOfIntegers);
    nullArrayOfStrings(arrayOfStrings);

    for (int i = 0; i < 32; i++) {
        std::cout << arrayOfIntegers[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 32; i++) {
        std::cout << arrayOfStrings[i] << " ";
    }
    std::cout << std::endl;

    reallocDemonstration();

    std::cout << "Return of Edward" << std::endl;

    return 0;
}
