#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Encryptor.h"
using namespace std;

// Функция для интерактивного режима
void interactiveMode() {
    cout << "\n=== ИНТЕРАКТИВНЫЙ РЕЖИМ ===\n";

    string inputFile, outputFile, key;
    int choice;

    Encryptor encryptor;

    do {
        cout << "\nМеню:\n";
        cout << "1. Установить ключ шифрования\n";
        cout << "2. Зашифровать файл\n";
        cout << "3. Расшифровать файл\n";
        cout << "4. Проверить двойным шифрованием\n";
        cout << "5. Демонстрация работы\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите ключ шифрования: ";
            cin >> key;
            encryptor.setKey(key);
            cout << "Ключ установлен: \"" << key << "\"" << endl;
            break;

        case 2:
            cout << "Введите имя входного файла: ";
            cin >> inputFile;
            cout << "Введите имя выходного файла: ";
            cin >> outputFile;
            encryptor.encryptFile(inputFile, outputFile);
            break;

        case 3:
            cout << "Введите имя зашифрованного файла: ";
            cin >> inputFile;
            cout << "Введите имя выходного файла: ";
            cin >> outputFile;
            encryptor.decryptFile(inputFile, outputFile);
            break;

        case 4: {
            cout << "Введите имя исходного файла для теста: ";
            cin >> inputFile;
            encryptor.testEncryption(inputFile);
            break;
        }

        case 5:
            Encryptor::demonstrate();
            break;

        case 0:
            cout << "Выход из программы.\n";
            break;

        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);
}

// Режим командной строки
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    cout << "ЛАБОРАТОРНАЯ РАБОТА 8 - ШИФРАТОР С ИСПОЛЬЗОВАНИЕМ КЛАССОВ ПОТОКОВ\n";
    cout << "================================================================\n";

    // Проверка аргументов командной строки
    if (argc == 4) {
        // Режим командной строки: программа.exe input.txt output.txt ключ
        cout << "\nРежим командной строки:" << endl;
        cout << "Входной файл: " << argv[1] << endl;
        cout << "Выходной файл: " << argv[2] << endl;
        cout << "Ключ: " << argv[3] << endl;

        Encryptor encryptor(argv[3]);
        encryptor.encryptFile(argv[1], argv[2]);

    }
    else if (argc > 1) {
        // Неправильное количество аргументов
        cout << "\nИспользование: " << argv[0] << " input.txt output.txt ключ" << endl;
        cout << "Пример: " << argv[0] << " secret.txt secret.enc mykey123" << endl;

    }
    else {
        // Интерактивный режим
        interactiveMode();
    }

    return 0;
}