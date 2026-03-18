#include <iostream>
using namespace std;

// 1. Передача по значению (НЕ меняет исходные переменные)
void obmen1(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

// 2. Передача по указателю (меняет исходные переменные)
void obmen2(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Передача по ссылке (меняет исходные переменные)
void obmen3(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 2, b = 5;

    cout << "before swap: a=" << a << ", b=" << b << endl;

    // obmen1 - передача по значению
    obmen1(a, b);
    cout << "after swap 1 (by value): a=" << a << ", b=" << b << endl;

    // obmen2 - передача по указателю
    a = 2; b = 5;
    obmen2(&a, &b);
    cout << "after swap 2 (by pointer): a=" << a << ", b=" << b << endl;

    // obmen3 - передача по ссылке
    a = 2; b = 5;
    obmen3(a, b);
    cout << "after swap 3 (by reference): a=" << a << ", b=" << b << endl;

    return 0;
}