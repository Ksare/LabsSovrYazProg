#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stroka.h"
#include <windows.h>
#include <locale>
using namespace std;

int main() {
    // Устанавливаем русскую локаль
    setlocale(LC_ALL, "Russian");

    // Устанавливаем кодировку консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Используем wcout для корректного вывода русских строк
    wcout.imbue(locale("Russian"));

    wcout << L"ЛАБОРАТОРНАЯ РАБОТА 6 - КЛАССЫ В C++\n";

    // Тестирование конструкторов
    wcout << L"\n--- Тест 1: Создание объектов ---\n";
    Stroka s1("qwerty");              // конструктор из C-строки
    Stroka s2;                         // конструктор по умолчанию
    Stroka s3(s1);                      // конструктор копирования
    Stroka s4(50);                      // конструктор с размером

    wcout << L"s1 = ";
    s1.print();
    wcout << L"\n";

    wcout << L"s3 (копия s1) = ";
    s3.print();
    wcout << L"\n";

    // Тестирование ввода
    wcout << L"\n--- Тест 2: Ввод строки ---\n";
    wcout << L"Введите строку для s2: ";
    s2.input();

    wcout << L"s2 = ";
    s2.print();
    wcout << L"\n";

    // Тестирование оператора присваивания
    wcout << L"\n--- Тест 3: Оператор присваивания ---\n";
    s4 = s2;
    wcout << L"s4 = s2 = ";
    s4.print();
    wcout << L"\n";

    // Тестирование оператора конкатенации
    wcout << L"\n--- Тест 4: Оператор конкатенации ---\n";
    Stroka s5 = s1 + s2;
    wcout << L"s5 = s1 + s2 = ";
    s5.print();
    wcout << L"\n";
    wcout << L"Длина s5 = " << s5.length() << L"\n";

    // Тестирование оператора сравнения
    wcout << L"\n--- Тест 5: Оператор сравнения ---\n";
    if (s1 == s3) {
        wcout << L"s1 и s3 равны\n";
    }
    else {
        wcout << L"s1 и s3 не равны\n";
    }

    if (s1 == s5) {
        wcout << L"s1 и s5 равны\n";
    }
    else {
        wcout << L"s1 и s5 не равны\n";
    }

    // Тестирование своего метода копирования
    wcout << L"\n--- Тест 6: Свой метод копирования ---\n";
    Stroka s6;
    s6.myStrcpy("Hello, World!");
    wcout << L"s6 = ";
    s6.print();
    wcout << L"\n";

    // Тест из задания (исходная программа)
    wcout << L"\n--- Тест 7: Исходная программа из задания ---\n";
    Stroka t1("qwert"), t3, t4(t1), t5;

    wcout << L"Введите строку для t3: ";
    t3.input();

    t3 = Stroka("asdfg");
    wcout << L"t3 = ";
    t3.print();
    wcout << L"\n";

    t5 = t1 + t3 + t4;
    wcout << L"Длина t5 = " << t5.length() << L"\n";
    wcout << L"t5 = ";
    t5.print();
    wcout << L"\n";

    if (t1 == t5) {
        wcout << L"Строки t1 и t5 равны\n";
    }
    else if (t1 == t4) {
        wcout << L"Строки t1 и t4 равны\n";
    }
    else {
        wcout << L"Строки не равны\n";
    }

    wcout << L"\nПрограмма завершена.\n";

    return 0;
}