#include <iostream>
#define N 20

using namespace std;

char* strchr(char* s, char c);
char* strrchr(char* s, int c);
int anychr(char* s, char* accept);
char* strcat (char* dest, char* src);
char* strncat (char* dest, char* src, int n);
int strcmp (char* str1, char* str2);
char* strcopy(char* toHere, char* fromHere);
char* strfind(char* hey, char* need);

int main(){
    char* s = new char[N];
    char c;
    char* p;
    cin >> s >> c;
    p = strchr(s, c);
    cout << *p;
}

char* strchr(char* s, char c){
    int i = 0;
    while (s[i] != '/0'){
        if (s[i] == c){
            return &s[i];
        }
        i++;
    }
    return NULL;
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
    return NULL;
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

char* strcat(char* dest, char* src){
    int i = 0, j = 0;
    while (dest[i] != '/0'){
        i++;
    }
    while (src[j] != '/0'){
        dest[i] = src[j];
        i++; j++;
    }
    dest[i] = '\0';
    return dest;
}

char* strncat(char* dest, char* src, int n){
    int i = 0, j = 0;
    while (dest[i] != '/0'){
        i++;
    }
    while (n > 0){
        dest[i] = src[j];
        i++; j++;
        n--;
    }
    dest[i] = '\0';
    return dest;
}

int strcmp(char* str1, char* str2){
    int i = 0, j = 0;
    while ((str1[i] != '/0')&&(str2[j] != '/0')&&(str1[i] == str2[j])){
         i++; j++;
    }
    if(str1[i] > str2[j]){
        return 1;
    }
    if(str1[i] < str2[j]){
        return -1;
    }
    return 0;
}

char* strcopy(char* toHere, char* fromHere){
    int i = 0, j = 0;
    while (fromHere[i] != '/0'){
        toHere[i] = fromHere[j];
        i++;
        j++;
    }
    toHere[i] = '\0';
    return toHere;
}

char* strfind(char* hey, char* need){
    int n = 0, i = 0;
    while (hey[i] != '/0'){
        if (strcmp (hey, need) == 0) {
            return hey;
        }
        i++;
        n++;
    }
    return NULL;
}
