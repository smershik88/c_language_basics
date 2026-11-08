#include <stdio.h>
#include <stdlib.h>

/*
В заданном интервале
Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для
массива. Прототип функции int count_between(int from, int to, int size, int a[])

Input format
Функция принимает значения концов отрезка from и to, размер массива, массив целых чисел.
Output format
Функция возвращает целое число - количество числе в интервале [from, to]
Examples
Input
4 6 1 2 3 4 5 6 7 8 9 10
Output
3
*/

int count_between(int from, int to, int size, int a[]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int    array[]    = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t array_size = sizeof array / sizeof *array;

    printf("%d", count_between(4, 6, (int)array_size, array));

    return EXIT_SUCCESS;
}

int count_between(int from, int to, int size, int a[])
{
    int count = 0;

    if (!a || size <= 0)
        return 0;

    if (from > to)
    {
        int tmp = from;
        from    = to;
        to      = tmp;
    }

    for (int i = 0; i < size; i++)
    {
        if (a[i] >= from && a[i] <= to)
            count++;
    }

    return count;
}
