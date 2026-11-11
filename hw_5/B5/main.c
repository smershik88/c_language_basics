#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define DEC_BASE 10

/*
Сумма цифр
Ввести целое число и найти сумму его цифр.

Формат входных данных
Одно целое число большее или равное нулю.
Формат результата
Одно число - сумма цифр
Примеры
Входные данные
1234
Результат работы
10
Входные данные
111
Результат работы
3
*/

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int32_t n          = 0;
    uint8_t digits_sum = 0;

    // printf("Input an integer >= 0: ");
    if (scanf("%" SCNd32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    if (n < 0)
    {
        return EXIT_FAILURE;
    }

    while (n)
    {
        digits_sum += (uint8_t)(n % DEC_BASE);
        n = n / DEC_BASE;
    }

    printf("%" PRIu8 "\n", digits_sum);

    return EXIT_SUCCESS;
}
