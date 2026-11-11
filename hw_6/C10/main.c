#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Простые множители
Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых
множителей числа. void print_simple(int n)

Формат входных данных
Целое положительное число.
Формат результата
Последовательность всех простых множителей данного числа в порядке возрастания.
Примеры
Входные данные
12
Результат работы
2 2 3
Входные данные
120
Результат работы
2 2 2 3 5
*/

void print_prime_factors(uint32_t n);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    if (scanf("%" SCNu32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    print_prime_factors(n);

    return EXIT_SUCCESS;
}

void print_prime_factors(uint32_t n)
{
    for (uint32_t i = 2; i <= n / i;)
    {
        if (n % i == 0)
        {
            printf("%" PRIu32 " ", i);
            n /= i;
        }
        else
        {
            i++;
        }
    }

    if (n > 1)
    {
        printf("%" PRIu32, n);
    }
}
