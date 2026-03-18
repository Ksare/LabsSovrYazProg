#pragma once
#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Encryptor {
private:
    string key;              // Ключ шифрования
    fstream file;            // Поток для работы с файлом

public:
    // Конструкторы
    Encryptor();                          // Конструктор по умолчанию
    Encryptor(const string& k);            // Конструктор с ключом

    // Деструктор
    ~Encryptor();                          // Закрывает файл, если открыт

    // Методы установки ключа
    void setKey(const string& k);
    string getKey() const { return key; }

    // Методы шифрования/дешифрования
    bool encryptFile(const string& inputFile, const string& outputFile);
    bool decryptFile(const string& inputFile, const string& outputFile);

    // Метод для проверки (двойное шифрование)
    bool testEncryption(const string& originalFile);

    // Статический метод для демонстрации
    static void demonstrate();
};

#endif