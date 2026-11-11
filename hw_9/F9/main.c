#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Поменять местами
Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет
его местами с последним элементом массива. Гарантируется, что в массиве только один такой элемент
или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять. Прототип
функции: void swap_negmax_last(int size, int a[])

Input format
Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых
чисел. Examples Input 1 -2 -3 -4 5 6 7 8 9 10 Output 1 10 -3 -4 5 6 7 8 9 -2
*/

void swap_negmax_last(int size, int a[]);
void print_array(int size, int a[]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int       array[]    = {-131, -460, 206, 62, 179, -180, 354, 289, 239, 275};
    const int array_size = (int)(sizeof array / sizeof *array);

    swap_negmax_last(array_size, array);
    print_array(array_size, array);

    return EXIT_SUCCESS;
}

void swap_negmax_last(int size, int a[])
{
    if (!a || size <= 0)
    {
        return;
    }

    int max_neg_index = -1;

    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            if (max_neg_index == -1)
            {
                max_neg_index = i;
                continue;
            }

            if (a[i] > a[max_neg_index])
            {
                max_neg_index = i;
            }
        }
    }

    if (max_neg_index != -1)
    {
        int tmp          = a[size - 1];
        a[size - 1]      = a[max_neg_index];
        a[max_neg_index] = tmp;
    }
}

void print_array(int size, int a[])
{
    if (!a || !size)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}
