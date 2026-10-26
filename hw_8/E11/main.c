#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Отсортировать по последней цифре
Считать массив из 10 элементов и отсортировать его по последней цифре.

Input format
10 целых чисел через пробел
Output format
Этот же массив отсортированный по последней цифре
Examples
Input
14  25  13  30  76  58  32  11  41  97
Output
30  11  41  32  13  14  25  76  97  58
Input
109 118 100 51 62 73 1007 16 4 555
Output
100 51 62 73 4 555 16 1007 118 109
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
void print_array(const int32_t *array, size_t n);
int cmp_int32_by_last_digit(const void *pa, const void *pb); 

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    int32_t array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;

    qsort(array, SIZE,
        sizeof array[0],
        cmp_int32_by_last_digit
    );
    print_array(array, SIZE);
    
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

void print_array(const int32_t *array, size_t n)
{
    if (!array || !n)
    return;

    for (size_t i = 0; i < n; i++)
        printf("%" PRId32 " ", array[i]);
}

int cmp_int32_by_last_digit(const void *pa, const void *pb)
{   
    int32_t a = *(const int32_t*)pa,
            b = *(const int32_t*)pb;

    uint8_t last_digit_a = (uint8_t)(a < 0 ? -a % 10 : a % 10),
            last_digit_b = (uint8_t)(b < 0 ? -b % 10 : b % 10);

    if (last_digit_a != last_digit_b)
        return (last_digit_a > last_digit_b) - (last_digit_a < last_digit_b);

    return (a > b) - (a < b);
}
