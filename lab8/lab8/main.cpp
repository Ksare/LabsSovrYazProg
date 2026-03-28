#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Stroka.h"
#include <iomanip>      
#include <windows.h>
using namespace std;

int main() {
    // Настройка кодировки
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "LABORATORY WORK 8 - INPUT/OUTPUT STREAMS\n";

    // Часть 1: Демонстрация перегруженных операторов << и >>
    cout << "\n--- Part 1: Operators << and >> ---\n";

    Stroka s1("Privet");
    Stroka s2;

    cout << "s1 = " << s1 << endl;
    cout << "Enter string for s2: ";
    cin >> s2;
    cout << "s2 = " << s2 << endl;
    cout << "Length of s2 = " << s2.dlinia() << endl;

    // Часть 2: Работа с файловыми потоками
    cout << "\n--- Part 2: Writing to file ---\n";

    ofstream outFile("test.txt");
    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return 1;
    }

    Stroka strings[] = {
        Stroka("First string"),
        Stroka("Second string"),
        Stroka("Third string")
    };

    for (int i = 0; i < 3; i++) {
        outFile << "String " << i + 1 << ": " << strings[i] << endl;
    }

    outFile.close();
    cout << "Data written to test.txt\n";

    // Часть 3: Чтение из файла
    cout << "\n--- Part 3: Reading from file ---\n";

    ifstream inFile("test.txt");
    if (!inFile) {
        cout << "Error opening file for reading!\n";
        return 1;
    }

    char buffer[256];
    cout << "Content of test.txt:\n";
    while (inFile.getline(buffer, sizeof(buffer))) {
        cout << buffer << endl;
    }

    inFile.close();

    // Часть 4: Форматированный вывод
    cout << "\n--- Part 4: Formatted output ---\n";

    Stroka s3("Formatting");

    cout << "Width 20: |" << setw(20) << s3 << "|" << endl;
    cout << "Width 30: |" << setw(30) << s3 << "|" << endl;
    cout << "Left align: |" << left << setw(30) << s3 << "|" << endl;
    cout << "Right align: |" << right << setw(30) << s3 << "|" << endl;

    // Часть 5: Массив строк
    cout << "\n--- Part 5: Array of strings ---\n";

    const int N = 3;
    Stroka arr[N];

    cout << "Enter " << N << " strings:\n";
    for (int i = 0; i < N; i++) {
        cout << "String " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nEntered strings:\n";
    for (int i = 0; i < N; i++) {
        cout << "arr[" << i << "] = " << arr[i]
            << " (length " << arr[i].dlinia() << ")" << endl;
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

    cout << "\nLongest string: " << arr[maxIdx]
        << " (length " << maxLen << ")" << endl;

    // Часть 6: Цепочка операций
    cout << "\n--- Part 6: Chain of operations ---\n";

    Stroka a("Hello");
    Stroka b("World");
    Stroka c = a + Stroka(" ") + b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = a + ' ' + b = " << c << endl;

    return 0;
}