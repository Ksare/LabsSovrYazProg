#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>  // Для работы с файловыми потоками
#include "Stroka.h"
#include <fstream>      
#include <iomanip>      
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "ЛАБОРАТОРНАЯ РАБОТА 8 - ПОТОКИ ВВОДА/ВЫВОДА\n";
    

    // Часть 1: Демонстрация перегруженных операторов << и >>
    cout << "\n--- Часть 1: Операторы << и >> ---\n";

    Stroka s1("Привет");
    Stroka s2;

    // Использование оператора вывода (<<)
    cout << "s1 = " << s1 << endl;

    // Использование оператора ввода (>>)
    cout << "Введите строку для s2: ";
    cin >> s2;
    cout << "s2 = " << s2 << endl;
    cout << "Длина s2 = " << s2.dlinia() << endl;

    // Часть 2: Работа с файловыми потоками
    cout << "\n--- Часть 2: Запись в файл ---\n";

    ofstream outFile("test.txt");  // Создаем выходной файловый поток
    if (!outFile) {
        cout << "Ошибка открытия файла для записи!\n";
        return 1;
    }

    // Запись объектов Stroka в файл
    Stroka strings[] = {
        Stroka("Первая строка"),
        Stroka("Вторая строка"),
        Stroka("Третья строка")
    };

    for (int i = 0; i < 3; i++) {
        outFile << "Строка " << i + 1 << ": " << strings[i] << endl;
    }

    outFile.close();
    cout << "Данные записаны в файл test.txt\n";

    // Часть 3: Чтение из файла
    cout << "\n--- Часть 3: Чтение из файла ---\n";

    ifstream inFile("test.txt");
    if (!inFile) {
        cout << "Ошибка открытия файла для чтения!\n";
        return 1;
    }

    char buffer[256];
    cout << "Содержимое файла test.txt:\n";
    while (inFile.getline(buffer, sizeof(buffer))) {
        cout << buffer << endl;
    }

    inFile.close();

    // Часть 4: Форматированный вывод
    cout << "\n--- Часть 4: Форматированный вывод ---\n";

    Stroka s3("Форматирование");

    // Использование манипуляторов потока
    cout << "Ширина поля 20: |" << setw(20) << s3 << "|" << endl;
    cout << "Ширина поля 30: |" << setw(30) << s3 << "|" << endl;
    cout << "Выравнивание влево: |" << left << setw(30) << s3 << "|" << endl;
    cout << "Выравнивание вправо: |" << right << setw(30) << s3 << "|" << endl;

    // Часть 5: Демонстрация работы с массивом строк
    cout << "\n--- Часть 5: Массив строк ---\n";

    const int N = 5;
    Stroka arr[N];

    cout << "Введите " << N << " строк:\n";
    for (int i = 0; i < N; i++) {
        cout << "Строка " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nВведенные строки:\n";
    for (int i = 0; i < N; i++) {
        cout << "arr[" << i << "] = " << arr[i]
            << " (длина " << arr[i].dlinia() << ")" << endl;
    }

    // Поиск самой длинной строки
    int maxLen = 0;
    int maxIdx = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i].dlinia() > maxLen) {
            maxLen = arr[i].dlinia();
            maxIdx = i;
        }
    }

    cout << "\nСамая длинная строка: " << arr[maxIdx]
        << " (длина " << maxLen << ")" << endl;

    // Часть 6: Демонстрация цепочки операций
    cout << "\n--- Часть 6: Цепочка операций ---\n";

    Stroka a("Hello");
    Stroka b("World");
    Stroka c = a + Stroka(" ") + b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = a + ' ' + b = " << c << endl;

    return 0;
}