#include <iostream>
#include "null.h"
#include "fill.h"

using namespace std;

int main() {
    int     *arrayOfIntegers = new int[32];
    string  *arrayOfStrings = new string[32];

    /**
     * Вызов функции time() возвращает системное время.
     * Благодаря тому, что вызов программы происходит в разный момент времени,
     * каждый раз числа будут генерироваться иначе, чем в предыдущих запусках программы.
     */
    srand(time(NULL));

    fillArrayOfIntegers(arrayOfIntegers);
    fillArrayOfStrings(arrayOfStrings);

    for (int i = 0; i < 32; i++) {
        cout << arrayOfIntegers[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 32; i++) {
        cout << arrayOfStrings[i] << " ";
    }
    cout << endl;

    nullArrayOfNumbers(arrayOfIntegers);
    nullArrayOfStrings(arrayOfStrings);

    for (int i = 0; i < 32; i++) {
        cout << arrayOfIntegers[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 32; i++) {
        cout << arrayOfStrings[i] << " ";
    }
    cout << endl;

    return 0;
}
