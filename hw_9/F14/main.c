#include <stdio.h>
#include <stdlib.h>

/*
Сумма в интервале
Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
Прототип функции int sum_between_ab(int from, int to, int size, int a[])

Input format
Функция принимает концы отрезка from и to, размер массива, массив целых чисел
Output format
Функция возвращает сумму элементов в интервале [from, to]
Examples
Input
4 6 1 2 3 4 5 6 7 8 9 10
Output
15
Input
6 4 1 2 3 4 5 6 7 8 9 10
Output
15
*/

int sum_between_ab(int from, int to, int size, int a[]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int    array[]    = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t array_size = sizeof array / sizeof *array;

    printf("%d", sum_between_ab(4, 6, (int)array_size, array));

    return EXIT_SUCCESS;
}

int sum_between_ab(int from, int to, int size, int a[])
{
    int sum = 0;

    if (!a || size <= 0)
    {
        return sum;
    }

    if (from > to)
    {
        int tmp = from;
        from    = to;
        to      = tmp;
    }

    for (int i = 0; i < size; i++)
    {
        if (a[i] >= from && a[i] <= to)
        {
            sum += a[i];
        }
    }

    return sum;
}
