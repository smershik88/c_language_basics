#include <stdio.h>
#include <stdlib.h>

/*
Поменять местами
Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
Прототип функции void change_max_min(int size, int a[])

Input format
Функция принимает на вход размер массива и массив чисел типа int
Output format
Функция не возвращает значения, измененный массив сохраняется на месте исходного.
Examples
Input
1 2 3 4 5 6 7 8 9 10
Output
10 2 3 4 5 6 7 8 9 1
*/

void change_max_min(int size, int a[]);
void print_array(int a[], size_t size);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int    array[]    = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t array_size = sizeof array / sizeof *array;

    print_array(array, array_size);
    change_max_min((int)array_size, array);
    puts("");
    print_array(array, array_size);

    return EXIT_SUCCESS;
}

void change_max_min(int size, int a[])
{
    if (!a || !size)
        return;

    int min_idx = 0, max_idx = 0;

    for (int i = 1; i < size; i++)
    {
        if (a[i] < a[min_idx])
            min_idx = i;
        else if (a[i] > a[max_idx])
            max_idx = i;
    }

    int tmp    = a[min_idx];
    a[min_idx] = a[max_idx];
    a[max_idx] = tmp;
}

void print_array(int a[], size_t size)
{
    if (!a || !size)
        return;

    for (size_t i = 0; i < size; i++)
        printf("%d ", a[i]);
}
