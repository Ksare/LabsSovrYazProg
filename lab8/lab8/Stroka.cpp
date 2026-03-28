#define _CRT_SECURE_NO_WARNINGS
#include "Stroka.h"
#include <cstring>
#include <cstdlib>
using namespace std;

// Глобальные вспомогательные функции
int myStrlenGlobal(const char* str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

void myStrcpyGlobal(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void myStrcatGlobal(char* dest, const char* src) {
    int destLen = myStrlenGlobal(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

int myStrcmpGlobal(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;
        if (str1[i] > str2[i]) return 1;
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    if (str1[i] == '\0') return -1;
    return 1;
}

// Реализация методов класса Stroka

Stroka::Stroka() {
    length = 0;
    str = new char[1];
    str[0] = '\0';
}

Stroka::Stroka(const char* s) {
    if (s == NULL) {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }
    else {
        length = myStrlenGlobal(s);
        str = new char[length + 1];
        myStrcpyGlobal(str, s);
    }
}

Stroka::Stroka(const Stroka& s) {
    length = s.length;
    str = new char[length + 1];
    myStrcpyGlobal(str, s.str);
}

Stroka::Stroka(int size) {
    if (size <= 0) size = 1;
    length = 0;
    str = new char[size + 1];
    str[0] = '\0';
}

Stroka::~Stroka() {
    delete[] str;
}

Stroka& Stroka::operator=(const Stroka& s) {
    if (this == &s) {
        return *this;
    }

    delete[] str;
    length = s.length;
    str = new char[length + 1];
    myStrcpyGlobal(str, s.str);

    return *this;
}

Stroka Stroka::operator+(const Stroka& s) const {
    Stroka result;
    delete[] result.str;

    result.length = length + s.length;
    result.str = new char[result.length + 1];

    myStrcpyGlobal(result.str, str);
    myStrcatGlobal(result.str, s.str);

    return result;
}

int Stroka::operator==(const Stroka& s) const {
    return (myStrcmpGlobal(str, s.str) == 0) ? 1 : 0;
}

int Stroka::dlinia() const {
    return length;
}

void Stroka::myStrcpy(const char* src) {
    if (src == NULL) return;

    delete[] str;
    length = myStrlenGlobal(src);
    str = new char[length + 1];

    int i = 0;
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
}

// ПЕРЕГРУЗКА ОПЕРАТОРОВ ВВОДА/ВЫВОДА

// Оператор вывода (<<) для ostream
ostream& operator<<(ostream& os, const Stroka& s) {
    os << s.str;
    return os;
}

// Оператор вывода (<<) для wostream
wostream& operator<<(wostream& os, const Stroka& s) {
    // Преобразуем char* в wchar_t* для вывода
    int len = s.dlinia();
    wchar_t* wstr = new wchar_t[len + 1];
    for (int i = 0; i < len; i++) {
        wstr[i] = s.c_str()[i];
    }
    wstr[len] = L'\0';
    os << wstr;
    delete[] wstr;
    return os;
}

// Оператор ввода (>>)
istream& operator>>(istream& is, Stroka& s) {
    char buffer[256];  // Временный буфер для ввода

    // Читаем строку (максимум 255 символов)
    is >> buffer;

    // Освобождаем старую память и создаем новую строку
    delete[] s.str;
    s.length = myStrlenGlobal(buffer);
    s.str = new char[s.length + 1];
    myStrcpyGlobal(s.str, buffer);

    return is;
}