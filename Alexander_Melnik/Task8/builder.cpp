#include "builder.h"

#include <iostream> // cout and more
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <cassert> // assert

size_t string_to_size_t(std::string);

std::string scramble(std::string); // TODO: refactor
std::string unscramble(std::string); // TODO: refactor

void testScramble();
void testUnscramble();

void initTask8() {

    std::cout << "Task8" << std::endl;

    std::cout << "Testing..." << std::endl;
    testScramble();
    testUnscramble();
    std::cout << "Tests passed!" << std::endl;
}

std::string scramble(std::string s) {

    if ( s.empty() )
        return s;

    std::string res;

    char prev = s[0];
    size_t quantity = 1;

    size_t i;
    for (i = 1; i < s.size(); i++) {
        if (s[i] == prev) {
            quantity++;
        } else {
            res += prev;
            if (quantity > 1) {
                res += std::to_string(quantity);
            }
            prev = s[i];
            quantity = 1;
        }
    }
    res += prev;
    if ((s[i - 1] == prev) && (quantity > 1)) {
        res += std::to_string(quantity);
    }

    return res;
}

std::string unscramble(std::string scr) {

    if ( scr.empty() )
        return scr;

    if ( isdigit(scr[0]) ) {
        throw std::runtime_error("First symbol of scrambled string can't be digit");
    }

    std::string res = "";

    std::string quantityToken;
    char symb = scr[0];

    for (size_t i = 1; i < scr.size(); i++) {
        if ( isdigit(scr[i]) ) {
            quantityToken += scr[i];
        } else {
            if ( !quantityToken.empty() ) {
                res += std::string(string_to_size_t(quantityToken), symb);
            } else {
                res += symb;
            }
            quantityToken.clear();
            symb = scr[i];
        }
    }
    if ( !quantityToken.empty() ) {
        res += std::string(string_to_size_t(quantityToken), symb);
    } else {
        res += symb;
    }

    return res;
}

void testScramble() {
    assert(scramble("qqqqqqqxxxuiixyz") == "q7x3ui2xyz");
    assert(scramble("abcd") == "abcd");
    assert(scramble("abbb") == "ab3");
}

void testUnscramble() {
    assert(unscramble("q7x3ui2xyz") == "qqqqqqqxxxuiixyz");
    assert(unscramble("abcd") == "abcd");
    assert(unscramble("ab3") == "abbb");
}

size_t string_to_size_t(std::string s) {

    std::stringstream ss(s);
    size_t res;

    ss >> res;

    return res;
}

