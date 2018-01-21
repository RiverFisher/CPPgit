#include <iostream>
#include <string.h>
#define N 49

using namespace std;

char* strcat (char* dest, char* src);
char* strncat (char* dest, char* src, int n);
char* strchr(char* s, char c);
char* strrchr(char* s, int c);
int strcmp (char* strn1, char* strn2);
char* strcopy(char* point2, char* point1);
int anychr(char* s, char* accept);
char* strsearch(char* haystack, char* needle);




int main(){
    char* s = new char[N];
    char c;
    char* p;
    cin >> s >> c;
    p = strrchr(s, c);
    cout << *p;
}

char* strcat(char* dest, char* src)
{
    int i = 0, j = 0;
    while (src[j] != '/0'){
        dest[i] = src[j];
        i++; j++;
    }
    while (dest[i] != '/0'){
        i++;
    }
    dest[i] = '\0';
    return dest;
}


char* strncat(char* dest, char* src, int n){
    int i = 0, j = 0;
    while (n > 0){
        dest[i] = src[j];
        i++; j++;
        n--;
    }
    while (dest[i] != '/0'){
        i++;
    }
    dest[i] = '\0';
    return dest;
}


char* strchr(char* s, char c){
    int i = 0;
    while (s[i] != '/0'){
        if (s[i] == c){
            return &s[i];
        }
        i++;
    }
    return 0;
}


char* strrchr(char* s, int c){
    int i = 0, j = 0;
    while (s[i] != '/0'){
        i++;
    }
    i--;
    while (s[i] != '/0'){
        if (s[i] == c) {
            return s;
        }
        i--;
    }
    return 0;
}


int strcmp(char* strn1, char* strn2){
    int i = 0, j = 0;
    while ((strn1[i] != '/0')&&(strn2[j] != '/0')&&(strn1[i] == strn2[j])){
         i++; j++;
    }
    if(strn1[i] > strn2[j]){
        return 1;
    }
    if(strn1[i] < strn2[j]){
        return -1;
    }
    return 0;
}


char* strcopy(char* point2, char* point1)
{
    int j = 0, i = 0;
    while (point1[i] != '/0')
        {
        point2[i] = point1[j];
        i++;
        j++;
    }
    point2[i] = '\0';
    return point2;
}


int anychr(char* s, char* accept){
    int i = 0, j = 0;
    while (s[i] != '/0'){
        while ((accept[j] != '/0') && (s[i] != accept[j])){
            j++;
        }
        if (accept[j] != '/0'){
            return i;
        }
    }
    return -1;
}


char* strsearch(char* haystack, char* needle){
    int n = 0, i = 0;
    while (haystack[i] != '/0'){
        if (strcmp (haystack, needle) == 0) {
            return haystack;
        }
        n++;
        i++;
    }
    return 0;
}
