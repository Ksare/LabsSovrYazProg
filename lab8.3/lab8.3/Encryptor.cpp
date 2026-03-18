#define _CRT_SECURE_NO_WARNINGS
#include "Encryptor.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Конструктор по умолчанию
Encryptor::Encryptor() : key("") {}

// Конструктор с ключом
Encryptor::Encryptor(const string& k) : key(k) {}

// Деструктор
Encryptor::~Encryptor() {
    if (file.is_open()) {
        file.close();
    }
}

// Установка ключа
void Encryptor::setKey(const string& k) {
    key = k;
}

// Шифрование файла
bool Encryptor::encryptFile(const string& inputFile, const string& outputFile) {
    // Проверка наличия ключа
    if (key.empty()) {
        cerr << "Ошибка: Ключ шифрования не установлен!" << endl;
        return false;
    }

    // Открытие входного файла для чтения в бинарном режиме
    ifstream in(inputFile, ios::binary);
    if (!in.is_open()) {
        cerr << "Ошибка: Не удалось открыть входной файл " << inputFile << endl;
        return false;
    }

    // Открытие выходного файла для записи в бинарном режиме
    ofstream out(outputFile, ios::binary);
    if (!out.is_open()) {
        cerr << "Ошибка: Не удалось создать выходной файл " << outputFile << endl;
        in.close();
        return false;
    }

    cout << "Шифрование файла " << inputFile << " с ключом \"" << key << "\"..." << endl;

    char ch;
    size_t keyIndex = 0;
    size_t keyLength = key.length();
    long fileSize = 0;

    // Чтение и шифрование
    while (in.get(ch)) {
        // XOR с символом ключа
        char encrypted = ch ^ key[keyIndex];
        out.put(encrypted);

        // Циклический переход по ключу
        keyIndex = (keyIndex + 1) % keyLength;
        fileSize++;
    }

    // Закрытие файлов
    in.close();
    out.close();

    cout << "Шифрование завершено. Обработано " << fileSize << " байт." << endl;
    cout << "Результат сохранен в " << outputFile << endl;

    return true;
}

// Дешифрование файла (тот же XOR)
bool Encryptor::decryptFile(const string& inputFile, const string& outputFile) {
    // Дешифрование - это то же самое, что и шифрование с тем же ключом
    return encryptFile(inputFile, outputFile);
}

// Тестирование двойным шифрованием
bool Encryptor::testEncryption(const string& originalFile) {
    cout << "\n=== Тестирование двойным шифрованием ===" << endl;

    string encrypted1 = "encrypted1.tmp";
    string encrypted2 = "encrypted2.tmp";

    // Первое шифрование
    if (!encryptFile(originalFile, encrypted1)) {
        return false;
    }

    // Второе шифрование (должно расшифровать)
    if (!encryptFile(encrypted1, encrypted2)) {
        return false;
    }

    // Сравнение исходного файла с результатом двойного шифрования
    cout << "\nСравнение исходного файла с результатом двойного шифрования:" << endl;

    ifstream f1(originalFile, ios::binary);
    ifstream f2(encrypted2, ios::binary);

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Ошибка при открытии файлов для сравнения" << endl;
        return false;
    }

    bool identical = true;
    long pos = 0;
    char c1, c2;

    while (f1.get(c1) && f2.get(c2)) {
        if (c1 != c2) {
            cout << "Несовпадение на позиции " << pos
                << ": 0x" << hex << (int)(unsigned char)c1
                << " vs 0x" << (int)(unsigned char)c2 << dec << endl;
            identical = false;
            break;
        }
        pos++;
    }

    // Проверка, что оба файла закончились
    if (identical && (!f1.eof() || !f2.eof())) {
        cout << "Файлы имеют разный размер" << endl;
        identical = false;
    }

    f1.close();
    f2.close();

    // Удаление временных файлов
    remove(encrypted1.c_str());
    remove(encrypted2.c_str());

    if (identical) {
        cout << "УСПЕХ: Двойное шифрование восстановило исходный файл!" << endl;
        return true;
    }
    else {
        cout << "ОШИБКА: Файлы различаются" << endl;
        return false;
    }
}

// Демонстрация работы
void Encryptor::demonstrate() {
    cout << "\n=== ДЕМОНСТРАЦИЯ РАБОТЫ ШИФРАТОРА ===\n";

    // Создание тестового файла
    string testFile = "test_original.txt";
    string encryptedFile = "test_encrypted.dat";
    string decryptedFile = "test_decrypted.txt";

    // Создаем тестовый файл с данными
    ofstream out(testFile);
    if (out.is_open()) {
        out << "Это тестовый файл для проверки шифратора.\n";
        out << "Он содержит несколько строк текста.\n";
        out << "1234567890\n";
        out << "!@#$%^&*()\n";
        out << "Строка с русским текстом.\n";
        out.close();
        cout << "Создан тестовый файл: " << testFile << endl;
    }

    // Создание шифратора с ключом
    Encryptor encryptor("SecretKey123");

    // Шифрование
    cout << "\n1. Шифрование файла:" << endl;
    encryptor.encryptFile(testFile, encryptedFile);

    // Дешифрование
    cout << "\n2. Дешифрование файла:" << endl;
    encryptor.decryptFile(encryptedFile, decryptedFile);

    // Проверка двойным шифрованием
    cout << "\n3. Проверка двойным шифрованием:" << endl;
    encryptor.testEncryption(testFile);

    // Вывод содержимого расшифрованного файла
    cout << "\n4. Содержимое расшифрованного файла:" << endl;
    ifstream in(decryptedFile);
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            cout << "  " << line << endl;
        }
        in.close();
    }

    // Очистка
    remove(testFile.c_str());
    remove(encryptedFile.c_str());
    remove(decryptedFile.c_str());
}