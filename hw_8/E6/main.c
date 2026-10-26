#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Среднее арифметическое массива
Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.

Input format
12 целых чисел через пробел
Output format
Среднее арифметическое в формате "%.2f"
Examples
Input
4 -5 3 10 -4 -6 8 -10 1 0 5 7
Output
1.08
Input
1 2 3 4 5 6 7 8 9 10 11 12
Output
6.50
*/

#define SIZE 12U

bool read_array(int32_t *array, size_t n);
double avg_array(const int32_t *array, size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;

    printf("%.2f\n", avg_array(array, SIZE));
    
    return EXIT_SUCCESS;
}

bool read_array(int32_t *array,  size_t n)
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

double avg_array(const int32_t *array, size_t size)
{
    if (!array || !size)
        return 0.0;

    int64_t sum = 0;

    for (size_t i = 0; i < size; i++)
        sum += array[i];
    
    return (double)sum / (double)size;
}
