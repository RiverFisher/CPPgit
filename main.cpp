#include <iostream>
#include "nullable.h"

using namespace std;

bool fillArrayOfIntegers(int *);
bool fillArrayOfStrings(string *);

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

    setArrayOfNumbersToZero(arrayOfIntegers);
    for (int i = 0; i < 32; i++) {
        cout << arrayOfIntegers[i] << " ";
    }
    cout << endl;

    return 0;
}

bool fillArrayOfIntegers(int *array) {
    int begin = 0, end = 32;
    for (int i = 0; i < 32; i++) {
        array[i] = begin + rand() % end;
    }
    return true;
}

bool fillArrayOfStrings(string *array) {
    int begin = 1, end = 32;
    string alphabet[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
        "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    for (int i = 0; i < 32; i++) {
        int numberOfLetters = begin + rand() % end;
        string word = "";
        for (int numberOfLetter = begin; numberOfLetter <= numberOfLetters; numberOfLetter++) {
            word += alphabet[0 + rand() % 26];
        }
        array[i] = word;
    }
    return true;
}