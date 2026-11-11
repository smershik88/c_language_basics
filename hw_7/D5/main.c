#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
В двоичную систему
Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную
функцию.

Input format
Целое не отрицательное число в десятичной системе счисления
Output format
Целое число в двоичной системе счисления
Examples
Input
5
Output
101
Input
8
Output
1000
*/

#define DEC_BASE 10

uint64_t dec_to_bin(uint32_t n);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    if (scanf("%" SCNu32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    printf("%" PRIu64, dec_to_bin(n));

    return EXIT_SUCCESS;
}

uint64_t dec_to_bin(uint32_t n)
{
    if (n < 2)
    {
        return n;
    }

    return dec_to_bin(n / 2) * DEC_BASE + n % 2;
}
