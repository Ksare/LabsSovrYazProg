#include <iostream>
using namespace std;

// Вариант 1: передача по значению (НЕ меняет исходные переменные)
void obmen1(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    // Здесь меняются только локальные копии
}

// Вариант 2: передача по указателю (меняет исходные переменные)
void obmen2(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // Меняем значения по адресам, которые хранят указатели
}

// Вариант 3: передача по ссылке (меняет исходные переменные)
void obmen3(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
    // Работаем напрямую с оригинальными переменными
}

int main()
{
    int a = 2, b = 5;

    cout << "before swap: a=" << a << ", b=" << b << endl;
    

    // Вызов obmen1 (по значению)
    obmen1(a, b);
    cout << "after swap 1 (by value): a=" << a << ", b=" << b << endl;

    // Вызов obmen2 (по указателю)
    a = 2; b = 5; // восстанавливаем исходные значения
    obmen2(&a, &b);
    cout << "after swap 2 (by pointer): a=" << a << ", b=" << b << endl;

    // Вызов obmen3 (по ссылке)
    a = 2; b = 5; // восстанавливаем исходные значения
    obmen3(a, b);
    cout << "after swap 3 (by reference): a=" << a << ", b=" << b << endl;

    return 0;
}