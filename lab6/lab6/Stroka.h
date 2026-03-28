// Stroka.h
#ifndef STROKA_H
#define STROKA_H

#include <iostream>
#include <cstring>
using namespace std;

class Stroka {
private:
    char* str;          // Указатель на строку
    int size;           // Размер выделенной памяти
    int len;            // Длина строки

public:
    // Конструкторы
    Stroka();                                    // Конструктор по умолчанию
    Stroka(const char* s);                       // Конструктор из C-строки
    Stroka(int sz);                              // Конструктор с размером
    Stroka(const Stroka& other);                 // Конструктор копирования

    // Деструктор
    ~Stroka();

    // Методы ввода/вывода
    void input();                                // Ввод строки с клавиатуры
    void print() const;                          // Вывод строки на экран

    // Операторы
    Stroka& operator=(const Stroka& other);      // Оператор присваивания
    Stroka operator+(const Stroka& other) const; // Оператор конкатенации
    bool operator==(const Stroka& other) const;  // Оператор сравнения

    // Служебные методы
    int length() const;                          // Возвращает длину строки

    // Собственный метод копирования (по аналогии с предыдущей лабой)
    void myStrcpy(const char* src);              // Копирование C-строки
};

// Реализация методов класса

// Конструктор по умолчанию
Stroka::Stroka() {
    size = 1;
    len = 0;
    str = new char[size];
    str[0] = '\0';
}

// Конструктор из C-строки
Stroka::Stroka(const char* s) {
    len = strlen(s);
    size = len + 1;
    str = new char[size];
    strcpy(str, s);
}

// Конструктор с размером
Stroka::Stroka(int sz) {
    size = sz;
    len = 0;
    str = new char[size];
    str[0] = '\0';
}

// Конструктор копирования
Stroka::Stroka(const Stroka& other) {
    len = other.len;
    size = other.size;
    str = new char[size];
    strcpy(str, other.str);
}

// Деструктор
Stroka::~Stroka() {
    delete[] str;
}

// Ввод строки с клавиатуры
void Stroka::input() {
    char buffer[1000];
    cin >> buffer;

    delete[] str;
    len = strlen(buffer);
    size = len + 1;
    str = new char[size];
    strcpy(str, buffer);
}

// Вывод строки на экран
void Stroka::print() const {
    cout << str;
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& other) {
    if (this != &other) {
        delete[] str;
        len = other.len;
        size = other.size;
        str = new char[size];
        strcpy(str, other.str);
    }
    return *this;
}

// Оператор конкатенации (сложения строк)
Stroka Stroka::operator+(const Stroka& other) const {
    int newLen = len + other.len;
    int newSize = newLen + 1;
    char* temp = new char[newSize];

    strcpy(temp, str);
    strcat(temp, other.str);

    Stroka result(temp);
    delete[] temp;

    return result;
}

// Оператор сравнения
bool Stroka::operator==(const Stroka& other) const {
    return strcmp(str, other.str) == 0;
}

// Возвращает длину строки
int Stroka::length() const {
    return len;
}

// Собственный метод копирования (аналог myStrcpy из предыдущей лабы)
void Stroka::myStrcpy(const char* src) {
    delete[] str;
    len = strlen(src);
    size = len + 1;
    str = new char[size];
    strcpy(str, src);
}

#endif // STROKA_H