#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма цифр числа
Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.
int sum_digits(int n)

Input format
Одно натуральное число.
Output format
Целое число - сумма цифр введенного числа.
Examples
Input
123
Output
6
Input
1000
Output
1
*/

#define DEC_BASE 10

uint32_t sum_digits(uint32_t n);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    if (scanf("%" SCNu32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    printf("%" PRIu32, sum_digits(n));

    return EXIT_SUCCESS;
}

uint32_t sum_digits(uint32_t n)
{
    if (n < DEC_BASE)
    {
        return n;
    }

    return sum_digits(n / DEC_BASE) + n % DEC_BASE;
}
