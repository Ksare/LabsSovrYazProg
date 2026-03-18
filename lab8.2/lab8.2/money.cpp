#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Stroka.h"  // Только #include, без кода класса!
using namespace std;

// Класс Money для работы с денежными суммами
class Money {
private:
    long dollars;   // Доллары
    int cents;      // Центы

public:
    // Конструкторы
    Money() : dollars(0), cents(0) {}
    Money(long d, int c) : dollars(d), cents(c) {}

    // Перегрузка оператора сравнения >
    int operator>(const Money& amt) const {
        return (dollars > amt.dollars) ||
            ((dollars == amt.dollars) && (cents > amt.cents));
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Money& amt);

    // Для сортировки нужен оператор <
    int operator<(const Money& amt) const {
        return (dollars < amt.dollars) ||
            ((dollars == amt.dollars) && (cents < amt.cents));
    }
};

// Реализация оператора вывода
ostream& operator<<(ostream& os, const Money& amt) {
    os << "$" << amt.dollars << '.' << setw(2) << setfill('0') << amt.cents;
    return os;
}

// Шаблонная функция сортировки (пузырьковая)
template <class T>
void Sort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // Используем оператор >
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Специализация шаблона Sort для класса Stroka
template <>
void Sort<Stroka>(Stroka arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Для строк используем сравнение по длине
            if (arr[j].dlinia() > arr[j + 1].dlinia()) {
                Stroka temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Специализированная сортировка для Stroka (по длине)" << endl;
}

// Функция для демонстрации программы с Money
void programMoney() {
    cout << "\n=== ПРОГРАММА 1: Класс Money (стр. 22) ===\n";

    // Создаем массив объектов Money
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

    // Сортируем массив
    Sort(mas, size);

    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < size; i++) {
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }
}

// Функция для демонстрации работы с Stroka
void programStroka() {
    cout << "\n=== ПРОГРАММА 2: Работа с классом Stroka ===\n";

    Stroka arr[] = {
        Stroka("Банан"),
        Stroka("Апельсин"),
        Stroka("Вишня"),
        Stroka("Груша")
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив строк:\n";
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = \"" << arr[i]
            << "\" (длина " << arr[i].dlinia() << ")" << endl;
    }

    Sort(arr, size);

    cout << "\nОтсортированный массив (по длине):\n";
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = \"" << arr[i]
            << "\" (длина " << arr[i].dlinia() << ")" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    programMoney();
    programStroka();

    return 0;
}