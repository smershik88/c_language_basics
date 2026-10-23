#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Печать простых множителей
Составить рекурсивную функцию, печать всех простых множителей числа.

Формат входных данных
Натуральное число
Формат результата
Последовательность из всех простых делителей числа через пробел
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

void print_prime_factors(uint32_t n, uint32_t divisor);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);
    print_prime_factors(n, 2);
    
    return EXIT_SUCCESS;
}

void print_prime_factors(uint32_t n, uint32_t divisor)
{
    if (n <= 1)
        return;

    if (divisor * divisor > n)
    {
        printf("%" PRIu32 " ", n);
        return;
    }

    if (n % divisor == 0)
    {
        printf("%" PRIu32 " ", divisor);
        print_prime_factors(n / divisor, divisor);
    }
    else
    {
        print_prime_factors(n, divisor + 1);
    }
}
