#pragma once
#ifndef STROKA_H
#define STROKA_H

#include <iostream>
using namespace std;

class Stroka {
private:
    char* str;           // Указатель на строку в динамической памяти
    int length;          // Длина строки

public:
    // Конструкторы
    Stroka();                               // Конструктор по умолчанию
    Stroka(const char* s);                   // Конструктор из C-строки
    Stroka(const Stroka& s);                  // Конструктор копирования
    Stroka(int size);                         // Конструктор с заданным размером

    // Деструктор
    ~Stroka();                                 // Деструктор для освобождения памяти

    // Перегруженные операции
    Stroka& operator=(const Stroka& s);        // Присваивание
    Stroka operator+(const Stroka& s) const;   // Конкатенация
    int operator==(const Stroka& s) const;     // Сравнение

    // Методы
    int dlinia() const;                         // Определение длины строки
    const char* c_str() const { return str; }   // Получение C-строки

    // Дружественные функции для перегрузки операторов ввода/вывода
    friend ostream& operator<<(ostream& os, const Stroka& s);
    friend istream& operator>>(istream& is, Stroka& s);

    // Для wcout (широкие символы)
    friend wostream& operator<<(wostream& os, const Stroka& s);

    // Для совместимости со старым кодом
    void vvod() { cin >> *this; }
    void vyvod() const { cout << *this; }
    void myStrcpy(const char* src);
};

#endif