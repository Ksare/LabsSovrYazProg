#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ЗАДАНИЕ 1: Вывод содержимого файла на экран

// Функция для отображения содержимого файла
void displayFile(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        printf("Ошибка: Не удается открыть файл %s\n", filename);
        return;
    }

    int ch;
    printf("\nСодержимое файла:\n");
    while ((ch = getc(in)) != EOF) {
        putchar(ch);
    }
    printf("\n");

    fclose(in);
}

// Упрощенная версия задания 1 (сокращенный код)
void task1_simple() {
    char name[50];
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    FILE* in = fopen(name, "r");
    if (!in) {
        printf("Файл %s не может быть открыт\n", name);
        return;
    }

    int ch;
    while ((ch = getc(in)) != EOF) putchar(ch);
    fclose(in);
}

// ЗАДАНИЕ 2: Подсчет пустых и непустых символов

// Функция проверки, является ли символ "пустым" (не отображается на экране)
int isEmptyChar(int ch) {
    // Пустые символы: пробел, табуляция, новая строка, возврат каретки, звуковой сигнал и т.д.
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\a' || ch == '\b' || ch == '\v' || ch == '\f');
}

// Задание 2: Подсчет пустых и непустых символов в файле
void task2_countCharacters() {
    char name[50];
    printf("Введите имя файла для анализа: ");
    scanf("%s", name);

    FILE* in = fopen(name, "r");
    if (!in) {
        printf("Ошибка: Не удается открыть файл %s\n", name);
        return;
    }

    int emptyCount = 0;
    int nonEmptyCount = 0;
    int ch;
    int total = 0;

    while ((ch = getc(in)) != EOF) {
        if (isEmptyChar(ch)) {
            emptyCount++;
        }
        else {
            nonEmptyCount++;
        }
        total++;
    }

    fclose(in);

    printf("\n=== Статистика символов ===\n");
    printf("Всего символов: %d\n", total);
    printf("Пустых символов: %d\n", emptyCount);
    printf("Непустых символов: %d\n", nonEmptyCount);
    printf("Процент пустых: %.2f%%\n", (float)emptyCount / total * 100);
}

// ЗАДАНИЕ 3: Поиск подстроки в файле

// Функция поиска подстроки в файле и сохранения результатов
void searchInFile(const char* filename, const char* searchStr, const char* outputFile) {
    FILE* in = fopen(filename, "r");
    if (!in) {
        printf("Ошибка: Не удается открыть входной файл %s\n", filename);
        return;
    }

    FILE* out = fopen(outputFile, "w");
    if (!out) {
        printf("Ошибка: Не удается создать выходной файл %s\n", outputFile);
        fclose(in);
        return;
    }

    char buffer[1024];
    int lineNum = 0;
    int foundCount = 0;

    fprintf(out, "Результаты поиска подстроки \"%s\" в файле %s:\n\n", searchStr, filename);

    // Читаем файл построчно
    while (fgets(buffer, sizeof(buffer), in) != NULL) {
        lineNum++;

        // Ищем подстроку в текущей строке
        if (strstr(buffer, searchStr) != NULL) {
            foundCount++;
            fprintf(out, "Строка %d: %s", lineNum, buffer);
        }
    }

    fprintf(out, "\nВсего найдено: %d\n", foundCount);

    fclose(in);
    fclose(out);

    printf("Поиск завершен. Результаты сохранены в %s\n", outputFile);
    printf("Найдено %d строк, содержащих \"%s\"\n", foundCount, searchStr);
}

// Обертка для задания 3
void task3_search() {
    char filename[50];
    char searchStr[100];
    char outputFile[50] = "search_results.txt";

    printf("Введите имя файла для поиска: ");
    scanf("%s", filename);
    printf("Введите подстроку для поиска: ");
    scanf("%s", searchStr);

    searchInFile(filename, searchStr, outputFile);
}

// ЗАДАНИЕ 4: Обработка номеров страниц в текстовом файле
// Номера страниц находятся в первой строке каждой страницы, формат: - 34 -
// Нужно перенести их в последнюю строку страницы и убрать дефисы
void task4_processPageNumbers() {
    char filename[50];
    char outputFile[50];

    printf("Введите имя входного файла: ");
    scanf("%s", filename);
    printf("Введите имя выходного файла: ");
    scanf("%s", outputFile);

    FILE* in = fopen(filename, "r");
    if (!in) {
        printf("Ошибка: Не удается открыть входной файл %s\n", filename);
        return;
    }

    FILE* out = fopen(outputFile, "w");
    if (!out) {
        printf("Ошибка: Не удается создать выходной файл %s\n", outputFile);
        fclose(in);
        return;
    }

    char buffer[1024];
    char pageLines[100][1024];  // Храним строки текущей страницы
    int lineCount = 0;
    int pageNum = 0;

    printf("Обработка файла...\n");

    while (fgets(buffer, sizeof(buffer), in) != NULL) {
        // Проверяем конец страницы (два символа \f)
        if (strstr(buffer, "\f\f") != NULL) {
            // Обрабатываем текущую страницу, если есть строки
            if (lineCount > 0) {
                // Первая строка должна содержать номер страницы в формате "- ЧИСЛО -"
                char pageNumStr[20] = "";
                sscanf(pageLines[0], " - %s - ", pageNumStr);

                // Записываем все строки кроме первой в выходной файл
                for (int i = 1; i < lineCount; i++) {
                    fputs(pageLines[i], out);
                }

                // Добавляем номер страницы в конце (без дефисов)
                fprintf(out, "%s\n", pageNumStr);

                // Добавляем маркер конца страницы
                fputs("\f\f", out);
            }

            // Сбрасываем для следующей страницы
            lineCount = 0;
            pageNum++;
        }
        else {
            // Сохраняем строку для текущей страницы
            if (lineCount < 100) {
                strcpy(pageLines[lineCount], buffer);
                lineCount++;
            }
        }
    }

    // Обрабатываем последнюю страницу, если есть
    if (lineCount > 0) {
        char pageNumStr[20] = "";
        sscanf(pageLines[0], " - %s - ", pageNumStr);

        for (int i = 1; i < lineCount; i++) {
            fputs(pageLines[i], out);
        }
        fprintf(out, "%s\n", pageNumStr);
    }

    fclose(in);
    fclose(out);

    printf("Обработка завершена. Результат сохранен в %s\n", outputFile);
    printf("Обработано %d страниц\n", pageNum + 1);
}

// ЗАДАНИЯ 5 и 6: Шифрование/дешифрование файлов с аргументами командной строки

// Шифрование/дешифрование файла с использованием XOR и ключевой строки
// Параметры: inputFile - имя исходного файла, outputFile - имя выходного файла, key - ключ шифрования
void encryptFile(const char* inputFile, const char* outputFile, const char* key) {
    FILE* in = fopen(inputFile, "rb");  // Открываем в бинарном режиме
    if (!in) {
        printf("Ошибка: Не удается открыть входной файл %s\n", inputFile);
        return;
    }

    FILE* out = fopen(outputFile, "wb");
    if (!out) {
        printf("Ошибка: Не удается создать выходной файл %s\n", outputFile);
        fclose(in);
        return;
    }

    int keyLen = strlen(key);
    int keyIndex = 0;
    int ch;
    long fileSize = 0;

    printf("Шифрование файла %s с ключом \"%s\"...\n", inputFile, key);

    // Читаем каждый байт, выполняем XOR с символом ключа, записываем в выходной файл
    while ((ch = getc(in)) != EOF) {
        // XOR с текущим символом ключа
        unsigned char encrypted = ch ^ key[keyIndex];
        putc(encrypted, out);

        // Переходим к следующему символу ключа циклически
        keyIndex = (keyIndex + 1) % keyLen;
        fileSize++;
    }

    fclose(in);
    fclose(out);

    printf("Шифрование завершено. Обработано %ld байт.\n", fileSize);
    printf("Результат сохранен в %s\n", outputFile);
}

// Проверка шифрования двойным шифрованием (должен получиться оригинал)
void testEncryption(const char* originalFile, const char* key) {
    char encrypted1[100] = "encrypted1.tmp";
    char encrypted2[100] = "encrypted2.tmp";

    printf("\n=== Тестирование XOR шифрования ===\n");

    // Первое шифрование
    encryptFile(originalFile, encrypted1, key);

    // Второе шифрование (должно расшифровать)
    encryptFile(encrypted1, encrypted2, key);

    // Сравнение исходного файла с результатом двойного шифрования
    printf("\nСравнение исходного файла с результатом двойного шифрования:\n");

    FILE* f1 = fopen(originalFile, "rb");
    FILE* f2 = fopen(encrypted2, "rb");

    if (!f1 || !f2) {
        printf("Ошибка при открытии файлов для сравнения\n");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return;
    }

    int identical = 1;
    long pos = 0;
    int c1, c2;

    while ((c1 = getc(f1)) != EOF && (c2 = getc(f2)) != EOF) {
        if (c1 != c2) {
            printf("Несовпадение на позиции %ld: %d vs %d\n", pos, c1, c2);
            identical = 0;
            break;
        }
        pos++;
    }

    // Проверка, что оба файла закончились одновременно
    if (identical && (getc(f1) != EOF || getc(f2) != EOF)) {
        printf("Файлы имеют разный размер\n");
        identical = 0;
    }

    fclose(f1);
    fclose(f2);

    if (identical) {
        printf("УСПЕХ: Двойное шифрование восстановило исходный файл!\n");
    }
    else {
        printf("ОШИБКА: Файлы различаются\n");
    }

    // Удаляем временные файлы
    remove(encrypted1);
    remove(encrypted2);
}

// ЗАДАНИЕ 6: Использование аргументов командной строки
// Формат: program.exe input.txt output.txt ключ
int main(int argc, char* argv[]) {
    printf("ЛАБОРАТОРНАЯ РАБОТА 5 - РАБОТА С ФАЙЛАМИ\n");
    printf("========================================\n");

    // Проверка аргументов командной строки для задания 6
    if (argc == 4) {
        printf("\nРежим командной строки (Задание 6):\n");
        printf("Входной файл: %s\n", argv[1]);
        printf("Выходной файл: %s\n", argv[2]);
        printf("Ключ: %s\n", argv[3]);

        encryptFile(argv[1], argv[2], argv[3]);
        return 0;
    }

    // Интерактивный режим для остальных заданий
    int choice;

    do {
        printf("\nВыберите задание:\n");
        printf("1 - Вывод содержимого файла (Задание 1)\n");
        printf("2 - Подсчет пустых и непустых символов (Задание 2)\n");
        printf("3 - Поиск подстроки в файле (Задание 3)\n");
        printf("4 - Обработка номеров страниц (Задание 4)\n");
        printf("5 - Шифрование файла (Задания 5 и 6)\n");
        printf("6 - Тестирование шифрования\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            task1_simple();
            break;

        case 2:
            task2_countCharacters();
            break;

        case 3:
            task3_search();
            break;

        case 4:
            task4_processPageNumbers();
            break;

        case 5: {
            char filename[50], output[50], key[100];
            printf("Введите имя входного файла: ");
            scanf("%s", filename);
            printf("Введите имя выходного файла: ");
            scanf("%s", output);
            printf("Введите ключ шифрования: ");
            scanf("%s", key);
            encryptFile(filename, output, key);
            break;
        }

        case 6: {
            char filename[50], key[100];
            printf("Введите имя файла для тестирования: ");
            scanf("%s", filename);
            printf("Введите ключ шифрования: ");
            scanf("%s", key);
            testEncryption(filename, key);
            break;
        }

        case 0:
            printf("Программа завершена.\n");
            break;

        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}