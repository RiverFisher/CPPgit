#include <string>
#include "fill.h"

bool fillArrayOfIntegers(int *array) {
    int begin = 0, end = 32;
    for (int i = 0; i < 32; i++) {
        array[i] = begin + rand() % end;
    }
    return true;
}

bool fillArrayOfStrings(std::string *array) {
    int begin = 1, end = 32;
    std::string alphabet[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
                           "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    for (int i = 0; i < 32; i++) {
        int numberOfLetters = begin + rand() % end;
        std::string word = "";
        for (int numberOfLetter = begin; numberOfLetter <= numberOfLetters; numberOfLetter++) {
            word += alphabet[0 + rand() % 26];
        }
        array[i] = word;
    }
    return true;
}