#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма минимальна
Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int. Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна.

Input format
Последовательность из 30 целых чисел через пробел
Output format
Два целых числа через пробел
Examples
Input
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
Output
0 1
*/

#define ARRAY_SIZE 30

bool read_array(int32_t *array, size_t n);
void print_min_sum_pair(const int32_t array[], size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[ARRAY_SIZE] = {0};

    if (!read_array(array, ARRAY_SIZE))
        return EXIT_FAILURE;

    print_min_sum_pair(array, ARRAY_SIZE);

    return EXIT_SUCCESS;
}

bool read_array(int32_t *array, size_t n)
{
    if (!array || !n)
        return false;

    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%" SCNd32, array + i) != 1)
            return false;
    }
    
    return true;
}

void print_min_sum_pair(const int32_t array[], size_t size)
{
    if (!array || size < 2)
        return;

    size_t  idx_1 = 0,
            idx_2 = 1;

    for (size_t i = 2; i < size; i++)
    {
        if (array[i] < array[idx_1] || array[i] < array[idx_2])
        {
            if (array[idx_1]  >= array[idx_2])
                idx_1 = i;
            else
                idx_2 = i;
        }

        if (idx_1 > idx_2)
        {
            size_t tmp = idx_1;
            idx_1 = idx_2;
            idx_2 = tmp;
        }
    }
    
    printf("%zu %zu", idx_1, idx_2);
}
