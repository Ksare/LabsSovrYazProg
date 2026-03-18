#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

#define N 5

// Универсальная функция для поиска min/max в разных частях матрицы
float findValue(float m[N][N], bool findMin, bool lowerTri = false, bool upperTri = false, bool mainDiag = false, bool secDiag = false) {
    float val = (findMin) ? 1e9 : -1e9; // Большое число для min, маленькое для max

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Проверяем, попадает ли элемент в нужную область
            bool include = true;
            if (lowerTri && j > i) include = false;      // Нижний треугольник (j <= i)
            if (upperTri && j < i) include = false;      // Верхний треугольник (j >= i)
            if (mainDiag && i != j) include = false;     // Главная диагональ
            if (secDiag && j != N - 1 - i) include = false;  // Второстепенная диагональ

            if (include) {
                if (findMin) { if (m[i][j] < val) val = m[i][j]; }
                else { if (m[i][j] > val) val = m[i][j]; }
            }
        }
    }
    return val;
}

// Универсальная функция для среднего арифметического
float average(float m[N][N], bool lowerTri = false, bool upperTri = false) {
    float sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool include = true;
            if (lowerTri && j > i) include = false;
            if (upperTri && j < i) include = false;

            if (include) {
                sum += m[i][j];
                count++;
            }
        }
    }
    return (count > 0) ? sum / count : 0;
}

// Универсальная функция для сумм строк/столбцов
void sums(float m[N][N], float result[N], bool forRows) {
    for (int i = 0; i < N; i++) {
        result[i] = 0;
        for (int j = 0; j < N; j++) {
            if (forRows) result[i] += m[i][j];
            else result[i] += m[j][i];
        }
    }
}

// Универсальная функция для min/max строк/столбцов
void findRowColValues(float m[N][N], float result[N], bool findMin, bool forRows) {
    for (int i = 0; i < N; i++) {
        result[i] = (findMin) ? 1e9 : -1e9;
        for (int j = 0; j < N; j++) {
            float val = (forRows) ? m[i][j] : m[j][i];
            if (findMin) { if (val < result[i]) result[i] = val; }
            else { if (val > result[i]) result[i] = val; }
        }
    }
}

// Универсальная функция для средних строк/столбцов
void averagesRowCol(float m[N][N], float result[N], bool forRows) {
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            if (forRows) sum += m[i][j];
            else sum += m[j][i];
        }
        result[i] = sum / N;
    }
}

int main() {
    float m[N][N];

    // Заполнение матрицы
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = rand() / 10.;

    // Вывод матрицы
    cout << "Исходная матрица:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(8) << setprecision(5) << m[i][j];
        cout << endl;
    }
    cout << endl;

    // 1-2. Min и Max всей матрицы
    cout << "1. Минимум матрицы: " << findValue(m, true) << endl;
    cout << "2. Максимум матрицы: " << findValue(m, false) << endl;

    // 3-6. Min/Max треугольных частей
    cout << "3. Максимум нижнетреугольной: " << findValue(m, false, true) << endl;
    cout << "4. Максимум верхнетреугольной: " << findValue(m, false, false, true) << endl;
    cout << "5. Минимум нижнетреугольной: " << findValue(m, true, true) << endl;
    cout << "6. Минимум верхнетреугольной: " << findValue(m, true, false, true) << endl;

    // 7-10. Min/Max диагоналей
    cout << "7. Минимум главной диагонали: " << findValue(m, true, false, false, true) << endl;
    cout << "8. Максимум главной диагонали: " << findValue(m, false, false, false, true) << endl;
    cout << "9. Минимум второстепенной: " << findValue(m, true, false, false, false, true) << endl;
    cout << "10. Максимум второстепенной: " << findValue(m, false, false, false, false, true) << endl;

    // 11-13. Средние арифметические
    cout << "11. Среднее матрицы: " << average(m) << endl;
    cout << "12. Среднее нижнетреугольной: " << average(m, true) << endl;
    cout << "13. Среднее верхнетреугольной: " << average(m, false, true) << endl;

    // 14-15. Суммы строк и столбцов
    float rowSums[N], colSums[N];
    sums(m, rowSums, true);
    sums(m, colSums, false);

    cout << "\n14. Суммы строк:\n";
    for (int i = 0; i < N; i++) cout << "Строка " << i + 1 << ": " << rowSums[i] << endl;

    cout << "\n15. Суммы столбцов:\n";
    for (int i = 0; i < N; i++) cout << "Столбец " << i + 1 << ": " << colSums[i] << endl;

    // 16-19. Min/Max строк и столбцов
    float rowMins[N], rowMaxs[N], colMins[N], colMaxs[N];
    findRowColValues(m, rowMins, true, true);
    findRowColValues(m, rowMaxs, false, true);
    findRowColValues(m, colMins, true, false);
    findRowColValues(m, colMaxs, false, false);

    cout << "\n16. Мин строк: "; for (int i = 0; i < N; i++) cout << rowMins[i] << " ";
    cout << "\n17. Мин столбцов: "; for (int i = 0; i < N; i++) cout << colMins[i] << " ";
    cout << "\n18. Макс строк: "; for (int i = 0; i < N; i++) cout << rowMaxs[i] << " ";
    cout << "\n19. Макс столбцов: "; for (int i = 0; i < N; i++) cout << colMaxs[i] << " ";

    // 20-21. Средние строк и столбцов
    float rowAvgs[N], colAvgs[N];
    averagesRowCol(m, rowAvgs, true);
    averagesRowCol(m, colAvgs, false);

    cout << "\n\n20. Средние строк: "; for (int i = 0; i < N; i++) cout << rowAvgs[i] << " ";
    cout << "\n21. Средние столбцов: "; for (int i = 0; i < N; i++) cout << colAvgs[i] << " ";

    // 22. Суммы групповых частей
    float lowerSum = 0, upperSum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (i > j) lowerSum += m[i][j];
            else if (i < j) upperSum += m[i][j];
        }
    cout << "\n\n22. Суммы:\nНижняя: " << lowerSum << "\nВерхняя: " << upperSum << endl;

    // 23. Элемент, близкий к среднему
    float avg = average(m);
    float closest = m[0][0];
    float minDiff = abs(m[0][0] - avg);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            float diff = abs(m[i][j] - avg);
            if (diff < minDiff) {
                minDiff = diff;
                closest = m[i][j];
            }
        }
    cout << "23. Ближайший к среднему (" << avg << "): " << closest << endl;

    _getch();
    return 0;
}