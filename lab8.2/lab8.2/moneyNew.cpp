#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Stroka.h"
#include <string.h>  // для strcmp
using namespace std;


// КЛАСС MONEY (стр. 22)


class Money {
private:
    long dollars;
    int cents;

public:
    Money() : dollars(0), cents(0) {}
    Money(long d, int c) : dollars(d), cents(c) {}

    int operator>(const Money& amt) const {
        return (dollars > amt.dollars) ||
            ((dollars == amt.dollars) && (cents > amt.cents));
    }

    friend ostream& operator<<(ostream& os, const Money& amt);

    int operator<(const Money& amt) const {
        return (dollars < amt.dollars) ||
            ((dollars == amt.dollars) && (cents < amt.cents));
    }
};

ostream& operator<<(ostream& os, const Money& amt) {
    os << "$" << amt.dollars << '.' << setw(2) << setfill('0') << amt.cents;
    return os;
}


// ШАБЛОН СОРТИРОВКИ


template <class T>
void Sort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Специализация для Stroka
template <>
void Sort<Stroka>(Stroka arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].dlinia() > arr[j + 1].dlinia()) {
                Stroka temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Специализированная сортировка для Stroka (по длине)" << endl;
}


// ШАБЛОНЫ GETMAX (стр. 23 - Перегрузка шаблонов функций)


// Шаблон 1: для двух значений
template <class T>
T getmax(T t1, T t2) {
    cout << "  getmax(T, T) для двух значений" << endl;
    return t1 > t2 ? t1 : t2;
}

// Шаблон 2: для массива
template <class T>
T getmax(T t[], size_t size) {
    cout << "  getmax(T[], size_t) для массива" << endl;
    T retval = t[0];
    for (size_t i = 1; i < size; i++) {
        if (t[i] > retval) retval = t[i];
    }
    return retval;
}


// СПЕЦИАЛИЗАЦИЯ ШАБЛОНОВ (стр. 24)


// Специализация для C-строк (char*)
char* getmax(char* s1, char* s2) {
    cout << "  Специализированная getmax(char*, char*)" << endl;
    return strcmp(s1, s2) > 0 ? s1 : s2;
}

// Специализация для const char*
const char* getmax(const char* s1, const char* s2) {
    cout << "  Специализированная getmax(const char*, const char*)" << endl;
    return strcmp(s1, s2) > 0 ? s1 : s2;
}

// Специализация для Stroka
template <>
Stroka getmax<Stroka>(Stroka t1, Stroka t2) {
    cout << "  Специализированная getmax для Stroka" << endl;
    return t1.dlinia() > t2.dlinia() ? t1 : t2;
}


// ПРОГРАММА 1: Демонстрация класса Money (стр. 22)


void programMoney() {
    cout << "\n=== ПРОГРАММА 1: Класс Money (стр. 22) ===\n";

    Money mas[] = {
        Money(19, 10),
        Money(99, 99),
        Money(99, 95),
        Money(19, 95)
    };

    int size = sizeof(mas) / sizeof(mas[0]);

    cout << "Исходный массив:\n";
    for (int i = 0; i < size; i++) {
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }

    Sort(mas, size);

    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < size; i++) {
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }
}

// ПРОГРАММА 2: Перегрузка шаблонов функций (стр. 23)


void programTemplateOverload() {
    cout << "\n=== ПРОГРАММА 2: Перегрузка шаблонов (стр. 23) ===\n";

    // Тест с int
    int i1 = 3, i2 = 5;
    int mas[] = { 3, 9, 5, 8, 1 };
    size_t size = sizeof(mas) / sizeof(mas[0]);

    cout << "\nТест с int:" << endl;
    cout << "getmax(i1, i2) = " << getmax(i1, i2) << endl;
    cout << "getmax(mas, size) = " << getmax(mas, size) << endl;

    // Тест с double
    double d1 = 3.14, d2 = 2.71;
    double dmas[] = { 3.14, 2.71, 5.5, 1.23 };
    size_t dsize = sizeof(dmas) / sizeof(dmas[0]);

    cout << "\nТест с double:" << endl;
    cout << "getmax(d1, d2) = " << getmax(d1, d2) << endl;
    cout << "getmax(dmas, dsize) = " << getmax(dmas, dsize) << endl;
}

// ПРОГРАММА 3: Специализация шаблонов (стр. 24)

void programTemplateSpecialization() {
    cout << "\n=== ПРОГРАММА 3: Специализация шаблонов (стр. 24) ===\n";

    // Тест с int (использует общий шаблон)
    int i1 = 3, i2 = 5;
    cout << "\nint: getmax(3, 5) = " << getmax(i1, i2) << endl;

    // Тест с C-строками (использует специализацию)
    char str1[] = "abc";
    char str2[] = "xyz";
    cout << "char*: getmax('abc', 'xyz') = " << getmax(str1, str2) << endl;

    // Тест с const char* (использует специализацию)
    const char* s1 = "AAA";
    const char* s2 = "ZZZ";
    cout << "const char*: getmax('AAA', 'ZZZ') = " << getmax(s1, s2) << endl;

    // Тест со Stroka (использует специализацию)
    Stroka st1("Короткая");
    Stroka st2("Очень длинная строка");
    cout << "Stroka: getmax('" << st1 << "', '" << st2 << "') = '"
        << getmax(st1, st2) << "'" << endl;
}


// ПРОГРАММА 4: Демонстрация работы с классом Stroka


void programStroka() {
    cout << "\n=== ПРОГРАММА 4: Работа с классом Stroka ===\n";

    Stroka arr[] = {
        Stroka("Банан"),
        Stroka("Апельсин"),
        Stroka("Вишня"),
        Stroka("Груша"),
        Stroka("Яблоко")
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив строк:\n";
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = \"" << arr[i]
            << "\" (длина " << arr[i].dlinia() << ")" << endl;
    }

    // Сортировка
    Sort(arr, size);

    cout << "\nОтсортированный массив (по длине):\n";
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = \"" << arr[i]
            << "\" (длина " << arr[i].dlinia() << ")" << endl;
    }

    // Демонстрация getmax для массива Stroka
    Stroka maxStr = getmax(arr, size);
    cout << "\nСамая длинная строка: \"" << maxStr
        << "\" (длина " << maxStr.dlinia() << ")" << endl;
}


// ГЛАВНАЯ ФУНКЦИЯ


int main() {
    setlocale(LC_ALL, "Russian");

    cout << "ЛАБОРАТОРНАЯ РАБОТА 8 - ШАБЛОНЫ ФУНКЦИЙ\n";

    // Выполняем все программы
    programMoney();                 // стр. 22
    programTemplateOverload();      // стр. 23
    programTemplateSpecialization(); // стр. 24
    programStroka();                 // дополнительно

    cout << "\nПрограмма завершена.\n";
    return 0;
}