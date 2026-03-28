#define _CRT_SECURE_NO_WARNINGS  // Подавление предупреждений в Visual Studio

#include <iostream>
#include <cstring>      // Для стандартных функций (задание 1)
#include <cstdlib>      // Для malloc/free
#include <clocale>
#include <windows.h>
using namespace std;

// Задание 1: Демонстрация библиотечных функций 
void demonstrateLibraryFunctions() {
    cout << "\nЗадание 1: Стандартные функции\n";

    char str1[100] = "qwerty";
    char str2[100] = "1234567890";
    char str3[100];

    cout << "Исходные строки:\n";
    cout << "str1 = \"" << str1 << "\"\n";
    cout << "str2 = \"" << str2 << "\"\n\n";

    // 1. strlen() - вычисление длины строки
    cout << "1. strlen() - длина строки:\n";
    cout << "   длина str1 = " << strlen(str1) << endl;
    cout << "   длина str2 = " << strlen(str2) << endl << endl;

    // 2. strcpy() - копирование строки
    strcpy(str3, str1);
    cout << "2. strcpy() - копирование str1 в str3:\n";
    cout << "   str3 = \"" << str3 << "\"\n\n";

    // 3. strcat() - конкатенация (склеивание) строк
    strcpy(str3, str1);  // предварительно копируем str3
    strcat(str3, str2);
    cout << "3. strcat() - склеивание str1 + str2:\n";
    cout << "   str1 + str2 = \"" << str3 << "\"\n\n";

    // 4. strcmp() - сравнение строк
    cout << "4. strcmp() - сравнение строк:\n";
    cout << "   str1 vs str2: " << strcmp(str1, str2);
    if (strcmp(str1, str2) == 0) cout << " (строки равны)\n";
    else if (strcmp(str1, str2) < 0) cout << " (str1 < str2)\n";
    else cout << " (str1 > str2)\n";

    cout << "   str1 vs str1: " << strcmp(str1, str1);
    if (strcmp(str1, str1) == 0) cout << " (строки равны)\n";
}

// Задание 2: Свои функции (без библиотек) 

// 2.1 Три реализации вычисления длины строки

// Вариант 1: проход по индексам с счетчиком
int myStrlen1(const char* str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

// Вариант 2: проход с использованием указателей
int myStrlen2(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return (int)(ptr - str);  // преобразование разницы в int
}

// Вариант 3: рекурсивная функция
int myStrlen3(const char* str) {
    if (*str == '\0') return 0;
    return 1 + myStrlen3(str + 1);
}

// 2.2 Копирование строки 
void myStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// 2.3 Сравнение строк 
int myStrcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;
        if (str1[i] > str2[i]) return 1;
        i++;
    }

    // Если одна из строк закончилась, а другая нет
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    if (str1[i] == '\0') return -1;
    return 1;
}

// 2.4 Конкатенация строк
void myStrcat(char* dest, const char* src) {
    // Находим конец первой строки dest
    int destLen = myStrlen1(dest);

    // Копируем символы src в конец dest
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';  // добавляем терминатор
}

// Демонстрация работы своих функций (задание 2)
void demonstrateMyFunctions() {
    cout << "\nЗадание 2: Собственные функции\n";

    char str1[100] = "qwerty";
    char str2[100] = "1234567890";
    char str3[100];
    char str4[100];

    cout << "Исходные строки:\n";
    cout << "str1 = \"" << str1 << "\"\n";
    cout << "str2 = \"" << str2 << "\"\n\n";

    // Демонстрация функций длины
    cout << "1. Вычисление длины строки (три варианта):\n";
    cout << "   strlen(str1) = " << strlen(str1) << " (стандартная)\n";
    cout << "   myStrlen1(str1) = " << myStrlen1(str1) << " (проход по индексам)\n";
    cout << "   myStrlen2(str1) = " << myStrlen2(str1) << " (проход указателями)\n";
    cout << "   myStrlen3(str1) = " << myStrlen3(str1) << " (рекурсивная)\n\n";

    // Демонстрация копирования
    cout << "2. Копирование строки:\n";
    myStrcpy(str3, str1);
    cout << "   myStrcpy(str3, str1) -> str3 = \"" << str3 << "\"\n\n";

    // Демонстрация сравнения
    cout << "3. Сравнение строк:\n";
    cout << "   myStrcmp(str1, str2) = " << myStrcmp(str1, str2);
    if (myStrcmp(str1, str2) == 0) cout << " (равны)\n";
    else if (myStrcmp(str1, str2) < 0) cout << " (str1 < str2)\n";
    else cout << " (str1 > str2)\n";

    cout << "   myStrcmp(str1, str1) = " << myStrcmp(str1, str1);
    if (myStrcmp(str1, str1) == 0) cout << " (равны)\n\n";

    // Демонстрация конкатенации
    cout << "4. Конкатенация строк:\n";
    myStrcpy(str4, str1);  // копируем str1 в str4
    myStrcat(str4, str2);
    cout << "   myStrcat(str4, str2) -> str4 = \"" << str4 << "\"\n";
}

// Задание 3: Динамическая память 
void demonstrateDynamicMemory() {
    cout << "\nЗадание 3: Динамическая память\n";

    // Выделение памяти
    char* str1 = (char*)malloc(100 * sizeof(char));
    char* str2 = (char*)malloc(100 * sizeof(char));
    char* str3 = (char*)malloc(100 * sizeof(char));

    if (str1 == NULL || str2 == NULL || str3 == NULL) {
        cout << "Ошибка выделения памяти!\n";
        return;
    }

    // Инициализация строк в динамической памяти
    myStrcpy(str1, "qwerty");
    myStrcpy(str2, "1234567890");

    cout << "Строки в динамической памяти:\n";
    cout << "str1 = \"" << str1 << "\"\n";
    cout << "str2 = \"" << str2 << "\"\n";
    cout << "длина str1 = " << myStrlen1(str1) << endl;

    // Конкатенация
    myStrcpy(str3, str1);
    myStrcat(str3, str2);
    cout << "str1 + str2 = \"" << str3 << "\"\n";

    // Освобождение памяти
    free(str1);
    free(str2);
    free(str3);

    cout << "Память успешно освобождена\n";
}

// Задание 4: Массив строк
void demonstrateStringArray() {
    cout << "\nЗадание 4: Массив строк\n";

    // Создание массива строк в динамической памяти
    const int NUM_STRINGS = 5;
    char** strings = (char**)malloc(NUM_STRINGS * sizeof(char*));

    // Проверка выделения памяти
    if (strings == NULL) {
        cout << "Ошибка выделения памяти для массива строк!\n";
        return;
    }

    // Выделение памяти для каждой отдельной строки
    for (int i = 0; i < NUM_STRINGS; i++) {
        strings[i] = (char*)malloc(100 * sizeof(char));
        if (strings[i] == NULL) {
            cout << "Ошибка выделения памяти для строки " << i << "!\n";
            // Освобождаем уже выделенную память
            for (int j = 0; j < i; j++) {
                free(strings[j]);
            }
            free(strings);
            return;
        }
    }

    // Заполняем строки
    myStrcpy(strings[0], "Hello");
    myStrcpy(strings[1], "World");
    myStrcpy(strings[2], "C++");
    myStrcpy(strings[3], "Programming");
    myStrcpy(strings[4], "Language");

    cout << "Исходный массив строк:\n";
    for (int i = 0; i < NUM_STRINGS; i++) {
        cout << "strings[" << i << "] = \"" << strings[i]
            << "\", длина = " << myStrlen1(strings[i]) << endl;
    }

    // Демонстрация функций с массивом строк
    cout << "\nДемонстрация функций с массивом строк:\n";

    // Сравнение строк
    cout << "Сравнение strings[0] и strings[1]: ";
    int cmp = myStrcmp(strings[0], strings[1]);
    if (cmp == 0) cout << "равны\n";
    else if (cmp < 0) cout << "strings[0] < strings[1]\n";
    else cout << "strings[0] > strings[1]\n";

    // Конкатенация (создаем временную строку)
    char* temp = (char*)malloc(200 * sizeof(char));
    if (temp != NULL) {
        myStrcpy(temp, strings[2]);
        myStrcat(temp, strings[3]);
        cout << "Конкатенация strings[2] + strings[3] = \"" << temp << "\"\n";
        free(temp);
    }

    // Поиск самой длинной строки
    int maxLen = 0;
    int maxIdx = 0;
    for (int i = 0; i < NUM_STRINGS; i++) {
        int len = myStrlen1(strings[i]);
        if (len > maxLen) {
            maxLen = len;
            maxIdx = i;
        }
    }
    cout << "Самая длинная строка: strings[" << maxIdx
        << "] = \"" << strings[maxIdx] << "\" (длина " << maxLen << ")\n";

    // Освобождение памяти
    for (int i = 0; i < NUM_STRINGS; i++) {
        free(strings[i]);
    }
    free(strings);
    cout << "Память массива строк освобождена\n";
}

// Главная функция программы 
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Демонстрация задания 4 - Обработка текстовых строк\n";

    // Задание 1: Стандартные функции
    demonstrateLibraryFunctions();

    // Задание 2: Свои функции
    demonstrateMyFunctions();

    // Задание 3: Динамическая память
    demonstrateDynamicMemory();

    // Задание 4: Массив строк
    demonstrateStringArray();

    cout << "\nПрограмма завершена.\n";
    return 0;
}