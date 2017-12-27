#include "conventer.h"
#include <iostream>
#include <cassert>

using namespace std;

string convert(string);
string unconvert(string);

void testConvert();
void testUnconvert();

void Dmitry_Fedorenko::initTask8(){
    cout << "Task8 was run" << endl;

    cout << "Tests was run" << endl;
    testConvert();
    testUnconvert();
    cout << "Tests passed!" << endl;
}

string convert (string s){

    if (s.empty()) return "String is empty";

    string result;
    char c = s[0];
    int count(0);

    for (int i=0;i<s.size();i++){
        if (c == s[i]) count++;
        else{
            result += c;
            if (count > 1) result += to_string(count);
            count = 1;
            c = s[i];
        }
    }
    result += c;
    if (count > 1) result += to_string(count);

    return result;
}

string unconvert (string s){

    if (s.empty()) return "String is empty";

    string result;
    int count(0);
    char c = s[0];

    for (int i=0;i<s.size();i++){
        if (isdigit(s[i])) {
            count = int(s[i]) - 48;
            for (int j=count;j>0;j--) result += c;
            c = s[i+1];
        } else if (s[i] != c) {
            result += c;
            c = s[i];
        }
    }
    if (not (isdigit(s[s.size()]))) result += c;

    return result;
}

void testConvert (){
    assert(convert("qqqqqqqxxxiixyz") == "q7x3i2xyz");
    assert(convert("xyz") == "xyz");
    assert(convert("") == "String is empty");
}

void testUnconvert (){
    assert(unconvert("q7x3i2xyz") == "qqqqqqqxxxiixyz");
    assert(unconvert("xyz") == "xyz");
    assert(unconvert("") == "String is empty");
}

