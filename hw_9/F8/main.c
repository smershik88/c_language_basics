#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Пропущенное число
В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке, но одно из чисел пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число.

Input format
Последовательность целых чисел от M до N. M, N не превосходит 1000.
Output format
Одно целое число
Examples
Input
2   3   1   4   7   6   9   8  10   0
Output
5
Input
41 40 39 38 37 36 34 33 32 31 50 49 48 47 46 45 44 43 42 30 0
Output
35
*/

#define MAX_SIZE 999

size_t read_array_while_not_zero(uint32_t array[], size_t size);
uint32_t get_missing_number(const uint32_t array[], size_t size);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t array[MAX_SIZE] = {0};

    size_t count = read_array_while_not_zero(array, MAX_SIZE);
    uint32_t missing_number = get_missing_number(array, count);

    printf("%" PRIu32, missing_number);

    return EXIT_SUCCESS;
}

size_t read_array_while_not_zero(uint32_t array[], size_t size)
{
    size_t count = 0;

    if (!array || !size)
        return count;

    uint32_t number = 0;
    while(scanf("%" SCNu32, &number) == 1)
    {
        if (number == 0 || count == size)
            break;
        
        array[count++] = number;
    }

    return count;
}

uint32_t get_missing_number(const uint32_t array[], size_t size)
{
    uint32_t missing_number = 0;

    if (!array || size < 2)
        return missing_number;

    const size_t buffer_size = sizeof *array * size;
    uint32_t *buffer = malloc(buffer_size);
    if (!buffer)
        return missing_number;
    memcpy(buffer, array, buffer_size);

    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = i; j > 0 && buffer[j] < buffer[j - 1]; j--)
        {
                uint32_t tmp = buffer[j];
                buffer[j] = buffer[j - 1];
                buffer[j - 1] = tmp;
        }
    }

    for (size_t i = 1; i < size; i++)
    {
        if (buffer[i] - buffer[i - 1] > 1)
        {
            missing_number = buffer[i] - 1;
            break;
        }
    }
    
    free(buffer);
    return missing_number;
}
