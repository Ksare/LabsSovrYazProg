// Подключаем стандартную библиотеку ввода/вывода
#include <stdio.h>

// Макросы для вывода информации об указателях:
// %llu - для вывода unsigned long long (адреса)
// x - сам указатель (адрес), *x - значение по адресу, &x - адрес переменной-указателя
#define PR_INT(x) printf("Address=%llu, value=%d, ptr address=%llu\n", (unsigned long long)x, *x, (unsigned long long)&x)
#define PR_CHAR(x) printf("Address=%llu, value=%c, ptr address=%llu\n", (unsigned long long)x, *x, (unsigned long long)&x)
#define PR_DOUBLE(x) printf("Address=%llu, value=%.2f, ptr address=%llu\n", (unsigned long long)x, *x, (unsigned long long)&x)

int main()
{
    // Эксперимент с int
    int i_arr[] = { 10, 20, 30 };
    int* i_ptr1 = i_arr;
    int* i_ptr2 = &i_arr[2];

    printf("INT (size = %d bytes):\n", sizeof(int));
    PR_INT(i_ptr1);
    i_ptr1++;
    PR_INT(i_ptr1);
    printf("int pointers difference: %d\n\n", i_ptr2 - i_ptr1);

    // Эксперимент с char
    char c_arr[] = { 'A', 'B', 'C' };
    char* c_ptr1 = c_arr;
    char* c_ptr2 = &c_arr[2];

    printf("CHAR (size = %d byte):\n", sizeof(char));
    PR_CHAR(c_ptr1);
    c_ptr1++;
    PR_CHAR(c_ptr1);
    printf("char pointers difference: %d\n\n", c_ptr2 - c_ptr1);

    // Эксперимент с double
    double d_arr[] = { 1.1, 2.2, 3.3 };
    double* d_ptr1 = d_arr;
    double* d_ptr2 = &d_arr[2];

    printf("DOUBLE (size = %d bytes):\n", sizeof(double));
    PR_DOUBLE(d_ptr1);
    d_ptr1++;
    PR_DOUBLE(d_ptr1);
    printf("double pointers difference: %d\n", d_ptr2 - d_ptr1);

    return 0;
}