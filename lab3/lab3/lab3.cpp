#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция вывода массива
void printArray(int arr[], int n, const char* message = "") {
    cout << message;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 1. Метод "мини-макса" (он же сортировка выбором)
void minMaxSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int iMin = i;  // индекс минимального элемента

        // Поиск минимального элемента в неотсортированной части
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[iMin]) {
                iMin = j;
            }
        }

        // Обмен найденного минимального элемента с текущим
        if (iMin != i) {
            int temp = arr[i];
            arr[i] = arr[iMin];
            arr[iMin] = temp;
        }
    }
}

// 2.1 Метод "пузырька"
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // оптимизация: проверяем, были ли обмены

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // Если не было обменов, массив уже отсортирован
        if (!swapped) break;
    }
}

// 2.2 Быстрая сортировка (рекурсивная)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // опорный элемент
    int i = low - 1;        // индекс меньшего элемента

    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++;
            // Меняем местами
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Ставим опорный элемент на правильное место
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;  // возвращаем индекс опорного элемента
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi - индекс опорного элемента, после partition он на своем месте
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы до и после опорного
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Обертка для быстрой сортировки (для удобства вызова)
void quickSort(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

// 3. Сортировка: четные по возрастанию, нечетные по убыванию
void sortEvenAscOddDesc(int arr[], int n) {
    // Создаем временные массивы для четных и нечетных
    int* evens = new int[n];
    int* odds = new int[n];
    int evenCount = 0, oddCount = 0;

    // Разделяем четные и нечетные
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evens[evenCount++] = arr[i];
        }
        else {
            odds[oddCount++] = arr[i];
        }
    }

    // Сортируем четные по возрастанию
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = 0; j < evenCount - i - 1; j++) {
            if (evens[j] > evens[j + 1]) {
                int temp = evens[j];
                evens[j] = evens[j + 1];
                evens[j + 1] = temp;
            }
        }
    }

    // Сортируем нечетные по убыванию
    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = 0; j < oddCount - i - 1; j++) {
            if (odds[j] < odds[j + 1]) {
                int temp = odds[j];
                odds[j] = odds[j + 1];
                odds[j + 1] = temp;
            }
        }
    }

    // Собираем обратно
    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = evens[e++];
        }
        else {
            arr[i] = odds[o++];
        }
    }

    delete[] evens;
    delete[] odds;
}

// 4. Сортировка по возрастанию на интервале [n1, n2]
void sortAscInterval(int arr[], int n, int n1, int n2) {
    // Проверка корректности индексов
    if (n1 < 0) n1 = 0;
    if (n2 >= n) n2 = n - 1;
    if (n1 >= n2) return;

    // Пузырьковая сортировка только на заданном интервале
    for (int i = n1; i <= n2; i++) {
        for (int j = n1; j < n2 - (i - n1); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 5. Сортировка по убыванию на интервале [n1, n2]
void sortDescInterval(int arr[], int n, int n1, int n2) {
    // Проверка корректности индексов
    if (n1 < 0) n1 = 0;
    if (n2 >= n) n2 = n - 1;
    if (n1 >= n2) return;

    // Пузырьковая сортировка по убыванию
    for (int i = n1; i <= n2; i++) {
        for (int j = n1; j < n2 - (i - n1); j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для копирования массива
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    // Исходный массив из задания
    int original[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int n = sizeof(original) / sizeof(int);

    cout << "ЛАБОРАТОРНАЯ РАБОТА 3 - СОРТИРОВКИ МАССИВОВ\n";
    

    // Демонстрация работы каждого метода
    int* temp = new int[n];

    // 1. Метод мини-макса
    copyArray(original, temp, n);
    cout << "1. МЕТОД МИНИ-МАКСА (ВЫБОРОМ):\n";
    printArray(temp, n, "Исходный массив:      ");
    minMaxSort(temp, n);
    printArray(temp, n, "После сортировки:     ");
    cout << endl;

    // 2.1 Метод пузырька
    copyArray(original, temp, n);
    cout << "2.1 МЕТОД ПУЗЫРЬКА:\n";
    printArray(temp, n, "Исходный массив:      ");
    bubbleSort(temp, n);
    printArray(temp, n, "После сортировки:     ");
    cout << endl;

    // 2.2 Быстрая сортировка
    copyArray(original, temp, n);
    cout << "2.2 БЫСТРАЯ СОРТИРОВКА:\n";
    printArray(temp, n, "Исходный массив:      ");
    quickSort(temp, n);
    printArray(temp, n, "После сортировки:     ");
    cout << endl;

    // 3. Сортировка четных/нечетных
    copyArray(original, temp, n);
    cout << "3. ЧЕТНЫЕ ПО ВОЗРАСТАНИЮ, НЕЧЕТНЫЕ ПО УБЫВАНИЮ:\n";
    printArray(temp, n, "Исходный массив:      ");
    sortEvenAscOddDesc(temp, n);
    printArray(temp, n, "После сортировки:     ");
    cout << "   (четные: возрастание, нечетные: убывание)\n\n";

    // 4. Сортировка по возрастанию на интервале
    copyArray(original, temp, n);
    int n1 = 3, n2 = 8;  // интервал индексов
    cout << "4. СОРТИРОВКА ПО ВОЗРАСТАНИЮ НА ИНТЕРВАЛЕ [" << n1 << ", " << n2 << "]:\n";
    printArray(temp, n, "Исходный массив:      ");
    sortAscInterval(temp, n, n1, n2);
    printArray(temp, n, "После сортировки:     ");
    cout << "   (остальные элементы не изменились)\n\n";

    // 5. Сортировка по убыванию на интервале
    copyArray(original, temp, n);
    n1 = 2; n2 = 7;
    cout << "5. СОРТИРОВКА ПО УБЫВАНИЮ НА ИНТЕРВАЛЕ [" << n1 << ", " << n2 << "]:\n";
    printArray(temp, n, "Исходный массив:      ");
    sortDescInterval(temp, n, n1, n2);
    printArray(temp, n, "После сортировки:     ");
    cout << "   (остальные элементы не изменились)\n\n";

    delete[] temp;

    cout << "\nНажмите любую клавишу для завершения...";
    _getch();
    return 0;
}