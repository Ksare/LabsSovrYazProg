#define _CRT_SECURE_NO_WARNINGS
#include "Stroka.h"
#include <cstring>
using namespace std;

Stroka::Stroka() : length(0) {
    str = new char[1];
    str[0] = '\0';
}

Stroka::Stroka(const char* s) {
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

Stroka::Stroka(const Stroka& s) {
    length = s.length;
    str = new char[length + 1];
    strcpy(str, s.str);
}

Stroka::Stroka(int size) : length(0) {
    str = new char[size + 1];
    str[0] = '\0';
}

Stroka::~Stroka() {
    delete[] str;
}

Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        delete[] str;
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka& s) const {
    Stroka result;
    delete[] result.str;
    result.length = length + s.length;
    result.str = new char[result.length + 1];
    strcpy(result.str, str);
    strcat(result.str, s.str);
    return result;
}

int Stroka::operator==(const Stroka& s) const {
    return strcmp(str, s.str) == 0;
}

int Stroka::dlinia() const {
    return length;
}

ostream& operator<<(ostream& os, const Stroka& s) {
    os << s.str;
    return os;
}

istream& operator>>(istream& is, Stroka& s) {
    char buffer[256];
    is >> buffer;
    delete[] s.str;
    s.length = strlen(buffer);
    s.str = new char[s.length + 1];
    strcpy(s.str, buffer);
    return is;
}