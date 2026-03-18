#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>  // Добавляем для вектора
using namespace std;

// КЛАСС ДЛЯ ДЕМОНСТРАЦИИ СОСТОЯНИЙ ПОТОКОВ

class StreamStateDemo {
private:
    string filename;

public:
    StreamStateDemo(const string& fname) : filename(fname) {}

    // 1. Методы форматирования вывода
    void demonstrateFormatting() {
        cout << "\n=== 1. МЕТОДЫ ФОРМАТИРОВАНИЯ ===\n";

        double pi = 3.141592653589793;
        int number = 255;

        // Сохраняем текущее состояние
        ios_base::fmtflags oldFlags = cout.flags();
        streamsize oldPrecision = cout.precision();

        cout << "Обычный вывод: " << pi << endl;

        // Установка точности
        cout.precision(10);
        cout << "precision(10): " << pi << endl;

        // Фиксированная точность
        cout << fixed;
        cout << "fixed + precision(5): " << setprecision(5) << pi << endl;

        // Научная нотация
        cout << scientific;
        cout << "scientific: " << pi << endl;

        // Шестнадцатеричный вывод
        cout << hex << showbase;
        cout << "hex(255): " << number << endl;

        // Восстановление состояния
        cout.flags(oldFlags);
        cout.precision(oldPrecision);
    }

    // 2. Методы ширина поля и выравнивание
    void demonstrateWidthAndAlign() {
        cout << "\n=== 2. ШИРИНА ПОЛЯ И ВЫРАВНИВАНИЕ ===\n";

        string texts[] = { "Hello", "World", "C++", "Streams" };
        int numbers[] = { 123, 4567, 89, 12345 };

        // Сохраняем состояние
        ios_base::fmtflags oldFlags = cout.flags();

        cout << "\nВыравнивание вправо (по умолчанию):\n";
        for (int i = 0; i < 4; i++) {
            cout << "|" << setw(10) << texts[i]
                << "|" << setw(10) << numbers[i] << "|" << endl;
        }

        cout << "\nВыравнивание влево:\n";
        cout << left;
        for (int i = 0; i < 4; i++) {
            cout << "|" << setw(10) << texts[i]
                << "|" << setw(10) << numbers[i] << "|" << endl;
        }

        cout << "\nВыравнивание по центру (имитация):\n";
        for (int i = 0; i < 4; i++) {
            int w1 = 10;
            int w2 = 10;
            string t = texts[i];
            string n = to_string(numbers[i]);

            int leftPad1 = (w1 - t.length()) / 2;
            int rightPad1 = w1 - t.length() - leftPad1;

            int leftPad2 = (w2 - n.length()) / 2;
            int rightPad2 = w2 - n.length() - leftPad2;

            cout << "|" << string(leftPad1, ' ') << t << string(rightPad1, ' ')
                << "|" << string(leftPad2, ' ') << n << string(rightPad2, ' ')
                << "|" << endl;
        }

        // Восстановление
        cout.flags(oldFlags);
    }

    // 3. Методы fill и ширины
    void demonstrateFill() {
        cout << "\n=== 3. МЕТОДЫ FILL ===\n";

        int number = 42;

        // Сохраняем состояние
        char oldFill = cout.fill();
        ios_base::fmtflags oldFlags = cout.flags();

        cout << "Обычный вывод: [" << setw(10) << number << "]" << endl;

        cout.fill('*');
        cout << "fill('*'): [" << setw(10) << number << "]" << endl;

        cout.fill('.');
        cout << "fill('.'): [" << setw(10) << number << "]" << endl;

        // Комбинация с выравниванием
        cout << left;
        cout.fill('-');
        cout << "left + fill('-'): [" << setw(10) << number << "]" << endl;

        // Восстановление
        cout.fill(oldFill);
        cout.flags(oldFlags);
    }

    // 4. Флаги состояния потока
    void demonstrateStreamState() {
        cout << "\n=== 4. ФЛАГИ СОСТОЯНИЯ ПОТОКА ===\n";

        ifstream file(filename);

        cout << "Проверка состояния файла " << filename << ":\n";
        cout << "good(): " << file.good() << " - все хорошо" << endl;
        cout << "eof(): " << file.eof() << " - конец файла" << endl;
        cout << "fail(): " << file.fail() << " - ошибка операции" << endl;
        cout << "bad(): " << file.bad() << " - критическая ошибка" << endl;

        // Попытка чтения после конца файла
        cout << "\nЧтение после конца файла:\n";
        int x;
        file >> x;  // Попытка чтения числа из пустого файла

        cout << "После неудачного чтения:\n";
        cout << "fail(): " << file.fail() << endl;
        cout << "eof(): " << file.eof() << endl;

        // Сброс состояния
        file.clear();
        cout << "\nПосле clear():\n";
        cout << "fail(): " << file.fail() << endl;

        file.close();
    }

    // 5. Манипуляторы для разных систем счисления
    void demonstrateNumberBases() {
        cout << "\n=== 5. СИСТЕМЫ СЧИСЛЕНИЯ ===\n";

        int number = 255;

        // Сохраняем состояние
        ios_base::fmtflags oldFlags = cout.flags();

        cout << "dec: " << dec << number << endl;
        cout << "hex: " << hex << number << endl;
        cout << "oct: " << oct << number << endl;

        cout << showbase;
        cout << "hex with showbase: " << hex << number << endl;
        cout << "oct with showbase: " << oct << number << endl;

        cout << uppercase;
        cout << "hex uppercase: " << hex << number << endl;

        // Восстановление
        cout.flags(oldFlags);
    }

    // 6. Методы позиционирования в файле
    void demonstrateFilePositioning() {
        cout << "\n=== 6. ПОЗИЦИОНИРОВАНИЕ В ФАЙЛЕ ===\n";

        // Создаем тестовый файл
        ofstream out("position_test.txt");
        for (int i = 0; i < 10; i++) {
            out << "Строка " << i << "\n";
        }
        out.close();

        // Чтение с позиционированием
        ifstream in("position_test.txt");

        cout << "Текущая позиция: " << in.tellg() << endl;

        string line;
        getline(in, line);
        cout << "Прочитали: " << line << endl;
        cout << "Позиция после чтения: " << in.tellg() << endl;

        // Перемещение в начало
        in.seekg(0, ios::beg);
        cout << "После seekg(0, beg): " << in.tellg() << endl;

        // Перемещение в конец
        in.seekg(0, ios::end);
        cout << "После seekg(0, end): " << in.tellg() << endl;

        // Перемещение на 10 байт от начала
        in.seekg(10, ios::beg);
        cout << "После seekg(10, beg): " << in.tellg() << endl;

        in.close();

        // Удаляем тестовый файл
        remove("position_test.txt");
    }

    // 7. Использование stringstream
    void demonstrateStringStream() {
        cout << "\n=== 7. ИСПОЛЬЗОВАНИЕ STRINGSTREAM ===\n";

        stringstream ss;

        // Запись в stringstream
        ss << "Число: " << 42 << ", Дробь: " << 3.14159 << ", Шестн.: " << hex << 255;

        cout << "Содержимое stringstream: " << ss.str() << endl;

        // Чтение из stringstream
        string word;
        int number;
        double fraction;

        ss >> word >> number >> fraction;
        cout << "Прочитано: word=" << word << ", number=" << number
            << ", fraction=" << fraction << endl;

        // Очистка stringstream
        ss.str("");  // Очистка содержимого
        ss.clear();  // Сброс флагов состояния

        ss << "Новые данные";
        cout << "После очистки: " << ss.str() << endl;
    }

    // 8. Вставка методов в программу из лабораторной работы 5
    void integrateWithEncryptor() {
        cout << "\n=== 8. ИНТЕГРАЦИЯ С ШИФРАТОРОМ ===\n";

        // Создаем тестовый файл
        string testFile = "encrypt_test.txt";
        string encryptedFile = "encrypt_test.enc";

        ofstream out(testFile);
        out << "Это тестовый файл для шифрования.\n";
        out << "Он содержит несколько строк.\n";
        out.close();

        // Демонстрация методов потоков при шифровании
        ifstream in(testFile, ios::binary);
        ofstream outEnc(encryptedFile, ios::binary);

        if (in.is_open() && outEnc.is_open()) {
            cout << "Файлы открыты успешно\n";

            // Показываем позицию
            cout << "Начальная позиция в файле: " << in.tellg() << endl;

            // Устанавливаем форматирование для отчета
            cout << hex << showbase;
            cout << "Шифрование с отображением HEX кодов:\n";

            char ch;
            int count = 0;
            string key = "KEY";
            int keyIndex = 0;

            while (in.get(ch)) {
                // Показываем позицию каждые 10 байт
                if (count % 10 == 0) {
                    cout << "Позиция " << dec << count << ": ";
                }

                // Шифрование
                char encrypted = ch ^ key[keyIndex];
                outEnc.put(encrypted);

                // Показываем HEX значения
                cout << hex << setw(2) << setfill('0')
                    << (int)(unsigned char)encrypted << " ";

                keyIndex = (keyIndex + 1) % key.length();
                count++;

                if (count % 10 == 0) cout << endl;
            }

            cout << dec << "\nВсего обработано байт: " << count << endl;
            cout << "Конечная позиция: " << in.tellg() << endl;
        }

        in.close();
        outEnc.close();

        // Очистка
        remove(testFile.c_str());
        remove(encryptedFile.c_str());
    }
};

// СОБСТВЕННАЯ ПРОГРАММА, ИЛЛЮСТРИРУЮЩАЯ ВОЗМОЖНОСТИ ПОТОКОВ

class LogFormatter {
private:
    ofstream logFile;
    ostream* output;
    bool useFile;

public:
    LogFormatter() : output(&cout), useFile(false) {}

    bool openLogFile(const string& filename) {
        logFile.open(filename);
        if (logFile.is_open()) {
            output = &logFile;
            useFile = true;

            // Устанавливаем форматирование для лога
            logFile << "=== ЛОГ-ФАЙЛ ===\n";
            logFile << "Создан: " << __DATE__ << " " << __TIME__ << "\n";
            logFile << "================\n\n";

            return true;
        }
        return false;
    }

    void closeLogFile() {
        if (useFile) {
            logFile.close();
            output = &cout;
            useFile = false;
        }
    }

    // Метод с различными настройками форматирования
    template<typename T>
    LogFormatter& operator<<(const T& value) {
        *output << value;
        return *this;
    }

    // Специальный манипулятор для форматированного вывода
    LogFormatter& formatHex(int value) {
        ios_base::fmtflags oldFlags = output->flags();
        *output << "0x" << hex << value;
        output->flags(oldFlags);
        return *this;
    }

    // ИСПРАВЛЕННАЯ ВЕРСИЯ: используем указатели вместо ссылок
    LogFormatter& formatTable(const string items[], int sizes[], int count) {
        // Сохраняем состояние
        ios_base::fmtflags oldFlags = output->flags();
        char oldFill = output->fill();

        *output << left;
        output->fill('.');

        for (int i = 0; i < count; i++) {
            *output << "| " << setw(20) << items[i]
                << " | " << setw(10) << sizes[i] << " |\n";
        }

        // Восстанавливаем состояние
        output->fill(oldFill);
        output->flags(oldFlags);

        return *this;
    }

    // АЛЬТЕРНАТИВНАЯ ВЕРСИЯ: с использованием вектора
    LogFormatter& formatTableVector(const vector<string>& items, const vector<int>& sizes) {
        if (items.size() != sizes.size()) {
            *output << "Ошибка: размеры векторов не совпадают\n";
            return *this;
        }

        // Сохраняем состояние
        ios_base::fmtflags oldFlags = output->flags();
        char oldFill = output->fill();

        *output << left;
        output->fill('.');

        for (size_t i = 0; i < items.size(); i++) {
            *output << "| " << setw(20) << items[i]
                << " | " << setw(10) << sizes[i] << " |\n";
        }

        // Восстанавливаем состояние
        output->fill(oldFill);
        output->flags(oldFlags);

        return *this;
    }

    // Демонстрация всех методов
    void demonstrate() {
        cout << "\n=== ДЕМОНСТРАЦИЯ LOGFORMATTER ===\n";

        // Вывод в консоль с форматированием
        *this << "Обычный вывод: " << 42 << "\n";
        *this << "Шестнадцатеричный: ";
        formatHex(255);
        *this << "\n";

        // Табличный вывод с использованием массива
        string items[] = { "Процессор", "Память", "Диск", "Сеть" };
        int sizes[] = { 3500, 16384, 512000, 1000 };

        *this << "\nТаблица ресурсов (массив):\n";
        formatTable(items, sizes, 4);

        // Табличный вывод с использованием вектора
        vector<string> vecItems = { "Процессор", "Память", "Диск", "Сеть" };
        vector<int> vecSizes = { 3500, 16384, 512000, 1000 };

        *this << "\nТаблица ресурсов (вектор):\n";
        formatTableVector(vecItems, vecSizes);

        // Запись в файл
        if (openLogFile("log.txt")) {
            *this << "Этот текст записан в файл\n";
            *this << "Число: " << 12345 << "\n";
            *this << "HEX: ";
            formatHex(255);
            *this << "\n";

            *this << "\nТаблица в файле:\n";
            formatTable(items, sizes, 4);

            closeLogFile();
            cout << "Данные записаны в log.txt\n";
        }
    }
};


// ГЛАВНАЯ ФУНКЦИЯ

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "ЛАБОРАТОРНАЯ РАБОТА 8 - СОСТОЯНИЕ ПОТОКОВ\n";

    StreamStateDemo demo("test.txt");

    // Демонстрация всех методов
    demo.demonstrateFormatting();
    demo.demonstrateWidthAndAlign();
    demo.demonstrateFill();
    demo.demonstrateNumberBases();

    // Создаем тестовый файл для демонстрации состояния
    ofstream test("test.txt");
    test << "Тестовые данные\n";
    test.close();

    demo.demonstrateStreamState();
    demo.demonstrateFilePositioning();
    demo.demonstrateStringStream();
    demo.integrateWithEncryptor();

    // Собственная программа
    LogFormatter logger;
    logger.demonstrate();

    // Очистка
    remove("test.txt");

    cout << "\nПрограмма завершена.\n";
    return 0;
}