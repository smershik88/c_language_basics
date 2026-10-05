#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Простые множители
Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа. void print_simple(int n)

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

void print_simple(uint32_t n);

int main(int argc, char* argv[])
{
    uint32_t n = 0;

    scanf("%" SCNu32, &n);

    print_simple(n);

    return EXIT_SUCCESS;
}

void print_simple(uint32_t n)
{
    uint32_t lim = (uint32_t)sqrt(n);

    for (uint32_t i = 2; i <= lim;)
    {
        if (n % i == 0)
        {
            printf("%" PRId32 " ", i);
            n /= i;
        }
        else
        {
            i++;
        }
    }

    if (n > 1)
        printf("%" PRIu32, n);
}
