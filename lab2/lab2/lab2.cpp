#include <iostream>      // Современный заголовочный файл вместо iostream.h
#include <iomanip>       // Современный заголовочный файл вместо iomanip.h
#include <cstdlib>       // Современный заголовочный файл вместо stdlib.h
#include <conio.h>       // Этот файл может остаться для _getch()
using namespace std;     // Добавляем пространство имен std

#define N 5

// Прототипы функций
float findMin(float matrix[N][N]);
float findMax(float matrix[N][N]);
float findMaxLowerTriangular(float matrix[N][N]);
float findMaxUpperTriangular(float matrix[N][N]);
float findMinLowerTriangular(float matrix[N][N]);
float findMinUpperTriangular(float matrix[N][N]);
float findMinMainDiagonal(float matrix[N][N]);
float findMaxMainDiagonal(float matrix[N][N]);
float findMinSecondaryDiagonal(float matrix[N][N]);
float findMaxSecondaryDiagonal(float matrix[N][N]);
float calculateAverage(float matrix[N][N]);
float calculateAverageLowerTriangular(float matrix[N][N]);
float calculateAverageUpperTriangular(float matrix[N][N]);
void calculateRowSums(float matrix[N][N], float rowSums[N]);
void calculateColumnSums(float matrix[N][N], float colSums[N]);
void findRowMins(float matrix[N][N], float rowMins[N]);
void findColMins(float matrix[N][N], float colMins[N]);
void findRowMaxs(float matrix[N][N], float rowMaxs[N]);
void findColMaxs(float matrix[N][N], float colMaxs[N]);
void calculateRowAverages(float matrix[N][N], float rowAvgs[N]);
void calculateColAverages(float matrix[N][N], float colAvgs[N]);
void calculateGroupSums(float matrix[N][N], float& lowerSum, float& upperSum);
float findClosestToAverage(float matrix[N][N]);

int main()  // В современном C++ main должен возвращать int
{
    float m[N][N];
    int i, j;

    // Заполнение матрицы случайными числами
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m[i][j] = rand() / 10.;

    // Вывод исходной матрицы
    cout << "Исходная матрица:\n";
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            cout << setw(8) << setprecision(5) << m[i][j];
        cout << endl;
    }
    cout << endl;

    // 1. Минимум матрицы
    cout << "1. Минимум матрицы: " << findMin(m) << endl;

    // 2. Максимум матрицы
    cout << "2. Максимум матрицы: " << findMax(m) << endl;

    // 3. Максимум нижнетреугольной части
    cout << "3. Максимум нижнетреугольной части: " << findMaxLowerTriangular(m) << endl;

    // 4. Максимум верхнетреугольной части
    cout << "4. Максимум верхнетреугольной части: " << findMaxUpperTriangular(m) << endl;

    // 5. Минимум нижнетреугольной части
    cout << "5. Минимум нижнетреугольной части: " << findMinLowerTriangular(m) << endl;

    // 6. Минимум верхнетреугольной части
    cout << "6. Минимум верхнетреугольной части: " << findMinUpperTriangular(m) << endl;

    // 7. Минимум главной диагонали
    cout << "7. Минимум главной диагонали: " << findMinMainDiagonal(m) << endl;

    // 8. Максимум главной диагонали
    cout << "8. Максимум главной диагонали: " << findMaxMainDiagonal(m) << endl;

    // 9. Минимум второстепенной диагонали
    cout << "9. Минимум второстепенной диагонали: " << findMinSecondaryDiagonal(m) << endl;

    // 10. Максимум второстепенной диагонали
    cout << "10. Максимум второстепенной диагонали: " << findMaxSecondaryDiagonal(m) << endl;

    // 11. Среднеарифметическое значение элементов матрицы
    cout << "11. Среднее арифметическое матрицы: " << calculateAverage(m) << endl;

    // 12. Среднее арифметическое нижнетреугольной части
    cout << "12. Среднее арифметическое нижнетреугольной части: " << calculateAverageLowerTriangular(m) << endl;

    // 13. Среднее арифметическое верхнетреугольной части
    cout << "13. Среднее арифметическое верхнетреугольной части: " << calculateAverageUpperTriangular(m) << endl;

    // 14. Суммы строк
    float rowSums[N];
    calculateRowSums(m, rowSums);
    cout << "14. Суммы строк:\n";
    for (i = 0; i < N; i++)
        cout << "Строка " << i + 1 << ": " << rowSums[i] << endl;

    // 15. Суммы столбцов
    float colSums[N];
    calculateColumnSums(m, colSums);
    cout << "\n15. Суммы столбцов:\n";
    for (j = 0; j < N; j++)
        cout << "Столбец " << j + 1 << ": " << colSums[j] << endl;

    // 16. Минимальные значения строк
    float rowMins[N];
    findRowMins(m, rowMins);
    cout << "\n16. Минимальные значения строк:\n";
    for (i = 0; i < N; i++)
        cout << "Строка " << i + 1 << ": " << rowMins[i] << endl;

    // 17. Минимальные значения столбцов
    float colMins[N];
    findColMins(m, colMins);
    cout << "\n17. Минимальные значения столбцов:\n";
    for (j = 0; j < N; j++)
        cout << "Столбец " << j + 1 << ": " << colMins[j] << endl;

    // 18. Максимальные значения строк
    float rowMaxs[N];
    findRowMaxs(m, rowMaxs);
    cout << "\n18. Максимальные значения строк:\n";
    for (i = 0; i < N; i++)
        cout << "Строка " << i + 1 << ": " << rowMaxs[i] << endl;

    // 19. Максимальные значения столбцов
    float colMaxs[N];
    findColMaxs(m, colMaxs);
    cout << "\n19. Максимальные значения столбцов:\n";
    for (j = 0; j < N; j++)
        cout << "Столбец " << j + 1 << ": " << colMaxs[j] << endl;

    // 20. Среднеарифметические значения строк
    float rowAvgs[N];
    calculateRowAverages(m, rowAvgs);
    cout << "\n20. Средние арифметические строк:\n";
    for (i = 0; i < N; i++)
        cout << "Строка " << i + 1 << ": " << rowAvgs[i] << endl;

    // 21. Среднеарифметические значения столбцов
    float colAvgs[N];
    calculateColAverages(m, colAvgs);
    cout << "\n21. Средние арифметические столбцов:\n";
    for (j = 0; j < N; j++)
        cout << "Столбец " << j + 1 << ": " << colAvgs[j] << endl;

    // 22. Суммы нижне- и верхнегрупповых частей
    float lowerGroupSum, upperGroupSum;
    calculateGroupSums(m, lowerGroupSum, upperGroupSum);
    cout << "\n22. Суммы групповых частей:\n";
    cout << "Нижнегрупповая часть: " << lowerGroupSum << endl;
    cout << "Верхнегрупповая часть: " << upperGroupSum << endl;

    // 23. Элемент, наиболее близкий к среднему арифметическому
    cout << "\n23. Элемент, наиболее близкий к среднему арифметическому: "
        << findClosestToAverage(m) << endl;

    _getch();  // В Visual Studio вместо getch() используется _getch()
    return 0;  // Возвращаем 0 при успешном завершении
}

// Здесь идут все определения функций (они остаются без изменений)
// 1. Минимум матрицы
float findMin(float matrix[N][N])
{
    float min = matrix[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix[i][j] < min)
                min = matrix[i][j];

    return min;
}

// 2. Максимум матрицы
float findMax(float matrix[N][N])
{
    float max = matrix[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix[i][j] > max)
                max = matrix[i][j];

    return max;
}

// 3. Максимум нижнетреугольной части (включая главную диагональ)
float findMaxLowerTriangular(float matrix[N][N])
{
    float max = matrix[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (matrix[i][j] > max)
                max = matrix[i][j];

    return max;
}

// 4. Максимум верхнетреугольной части (включая главную диагональ)
float findMaxUpperTriangular(float matrix[N][N])
{
    float max = matrix[0][0];

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (matrix[i][j] > max)
                max = matrix[i][j];

    return max;
}

// 5. Минимум нижнетреугольной части
float findMinLowerTriangular(float matrix[N][N])
{
    float min = matrix[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (matrix[i][j] < min)
                min = matrix[i][j];

    return min;
}

// 6. Минимум верхнетреугольной части
float findMinUpperTriangular(float matrix[N][N])
{
    float min = matrix[0][0];

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (matrix[i][j] < min)
                min = matrix[i][j];

    return min;
}

// 7. Минимум главной диагонали
float findMinMainDiagonal(float matrix[N][N])
{
    float min = matrix[0][0];

    for (int i = 1; i < N; i++)
        if (matrix[i][i] < min)
            min = matrix[i][i];

    return min;
}

// 8. Максимум главной диагонали
float findMaxMainDiagonal(float matrix[N][N])
{
    float max = matrix[0][0];

    for (int i = 1; i < N; i++)
        if (matrix[i][i] > max)
            max = matrix[i][i];

    return max;
}

// 9. Минимум второстепенной диагонали
float findMinSecondaryDiagonal(float matrix[N][N])
{
    float min = matrix[0][N - 1];

    for (int i = 1; i < N; i++)
        if (matrix[i][N - 1 - i] < min)
            min = matrix[i][N - 1 - i];

    return min;
}

// 10. Максимум второстепенной диагонали
float findMaxSecondaryDiagonal(float matrix[N][N])
{
    float max = matrix[0][N - 1];

    for (int i = 1; i < N; i++)
        if (matrix[i][N - 1 - i] > max)
            max = matrix[i][N - 1 - i];

    return max;
}

// 11. Среднеарифметическое значение элементов матрицы
float calculateAverage(float matrix[N][N])
{
    float sum = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += matrix[i][j];

    return sum / (N * N);
}

// 12. Среднее арифметическое нижнетреугольной части
float calculateAverageLowerTriangular(float matrix[N][N])
{
    float sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
        {
            sum += matrix[i][j];
            count++;
        }

    return sum / count;
}

// 13. Среднее арифметическое верхнетреугольной части
float calculateAverageUpperTriangular(float matrix[N][N])
{
    float sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
        {
            sum += matrix[i][j];
            count++;
        }

    return sum / count;
}

// 14. Суммы строк
void calculateRowSums(float matrix[N][N], float rowSums[N])
{
    for (int i = 0; i < N; i++)
    {
        rowSums[i] = 0;
        for (int j = 0; j < N; j++)
            rowSums[i] += matrix[i][j];
    }
}

// 15. Суммы столбцов
void calculateColumnSums(float matrix[N][N], float colSums[N])
{
    for (int j = 0; j < N; j++)
    {
        colSums[j] = 0;
        for (int i = 0; i < N; i++)
            colSums[j] += matrix[i][j];
    }
}

// 16. Минимальные значения строк
void findRowMins(float matrix[N][N], float rowMins[N])
{
    for (int i = 0; i < N; i++)
    {
        rowMins[i] = matrix[i][0];
        for (int j = 1; j < N; j++)
            if (matrix[i][j] < rowMins[i])
                rowMins[i] = matrix[i][j];
    }
}

// 17. Минимальные значения столбцов
void findColMins(float matrix[N][N], float colMins[N])
{
    for (int j = 0; j < N; j++)
    {
        colMins[j] = matrix[0][j];
        for (int i = 1; i < N; i++)
            if (matrix[i][j] < colMins[j])
                colMins[j] = matrix[i][j];
    }
}

// 18. Максимальные значения строк
void findRowMaxs(float matrix[N][N], float rowMaxs[N])
{
    for (int i = 0; i < N; i++)
    {
        rowMaxs[i] = matrix[i][0];
        for (int j = 1; j < N; j++)
            if (matrix[i][j] > rowMaxs[i])
                rowMaxs[i] = matrix[i][j];
    }
}

// 19. Максимальные значения столбцов
void findColMaxs(float matrix[N][N], float colMaxs[N])
{
    for (int j = 0; j < N; j++)
    {
        colMaxs[j] = matrix[0][j];
        for (int i = 1; i < N; i++)
            if (matrix[i][j] > colMaxs[j])
                colMaxs[j] = matrix[i][j];
    }
}

// 20. Среднеарифметические значения строк
void calculateRowAverages(float matrix[N][N], float rowAvgs[N])
{
    float sum;

    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = 0; j < N; j++)
            sum += matrix[i][j];
        rowAvgs[i] = sum / N;
    }
}

// 21. Среднеарифметические значения столбцов
void calculateColAverages(float matrix[N][N], float colAvgs[N])
{
    float sum;

    for (int j = 0; j < N; j++)
    {
        sum = 0;
        for (int i = 0; i < N; i++)
            sum += matrix[i][j];
        colAvgs[j] = sum / N;
    }
}

// 22. Суммы нижне- и верхнегрупповых частей (без главной диагонали)
void calculateGroupSums(float matrix[N][N], float& lowerSum, float& upperSum)
{
    lowerSum = 0;
    upperSum = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i > j) // Нижний треугольник (без диагонали)
                lowerSum += matrix[i][j];
            else if (i < j) // Верхний треугольник (без диагонали)
                upperSum += matrix[i][j];
        }
}

// 23. Элемент, наиболее близкий по значению к среднеарифметическому
float findClosestToAverage(float matrix[N][N])
{
    float average = calculateAverage(matrix);
    float closest = matrix[0][0];
    float minDifference = (average > matrix[0][0]) ? (average - matrix[0][0]) : (matrix[0][0] - average);
    float difference;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            difference = (average > matrix[i][j]) ? (average - matrix[i][j]) : (matrix[i][j] - average);
            if (difference < minDifference)
            {
                minDifference = difference;
                closest = matrix[i][j];
            }
        }

    return closest;
}