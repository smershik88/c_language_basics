#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Вторая с конца ноль
Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.

Input format
10 целых чисел через пробел.
Output format
Целые числа через пробел, у котороых вторая с конца цифра - ноль
Examples
Input
40 105 203 1 14 1000 22 33 44 55
Output
105 203 1 1000
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
void print_array(const int32_t *array, size_t n);
bool is_zero_tens(int32_t n);
size_t filter_array(const int32_t *src_array, size_t src_array_size,
    int32_t* dest_array, size_t dest_array_size, bool (*predicate)(int32_t)
);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    int32_t array[SIZE] = {0};
    int32_t filtered_array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;
    
    const size_t n = filter_array(array, SIZE,
        filtered_array, SIZE, is_zero_tens
    );
    print_array(filtered_array, n);
    
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

bool is_zero_tens(int32_t n)
{
    return (n / 10) % 10 == 0;
}

size_t filter_array(const int32_t *src_array, size_t src_array_size,
    int32_t *dest_array, size_t dest_array_size, bool (*predicate)(int32_t)
)
{
    if (src_array == dest_array || src_array_size < dest_array_size ||
        !src_array || !dest_array ||
        !src_array_size || !dest_array_size || !predicate
    )
    {
        return 0;
    }

    size_t j = 0;

    for (size_t i = 0; i < src_array_size; i++)
    {
        if (predicate(src_array[i]))
            dest_array[j++] = src_array[i];
    }

    return j;
}
