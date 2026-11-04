#include <stdio.h>
#include <stdlib.h>

/*
Больше по модулю
Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько элементов превосходят по модулю максимальный элемент.
Прототип функции int count_bigger_abs(int n, int a[]);

Input format
Функция получает размер массива и массив целых чисел
Output format
Функция возвращает целое число раное количеству элементов превосходящих по модулю максимальный элемент.
Examples
Input
1 -20 3 4 -50 6 7 8 9 10
Output
2
*/

int count_bigger_abs(int n, int a[]);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int array[] = {1, -20, 3, 4, -50, 6, 7, 8, 9, 10};
    size_t array_size = sizeof array / sizeof *array;
    
    printf("%d", count_bigger_abs((int)array_size, array));

    return EXIT_SUCCESS;
}

int count_bigger_abs(int n, int a[])
{
    int count = 0;

    if (!a || n <= 0)
        return count;

    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        long long value_mod = a[i] > 0 ? a[i] : -a[i];

        if (value_mod > max)
            count++;
    }

    return count;
}
