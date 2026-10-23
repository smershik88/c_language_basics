#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.

Input format
Натуральное число
Output format
Целое число - количество единиц в двоичной записи числа.
Examples
Input
5
Output
2
Input
255
Output
8
*/

uint8_t number_of_bin_1(uint32_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);
    printf("%" PRIu8, number_of_bin_1(n));
    
    return EXIT_SUCCESS;
}

uint8_t number_of_bin_1(uint32_t n)
{
    if (n < 2)
        return (uint8_t)n;

    return (n & 1U) + number_of_bin_1(n >> 1);
}
