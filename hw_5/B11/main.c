#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Перевернуть число
Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.

Формат входных данных
Целое неотрицательное число
Формат результата
Целое не отрицательное число наоборот
Примеры
Входные данные
1234
Результат работы
4321
Входные данные
782
Результат работы
287
*/

#define DEC_BASE 10

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n          = 0;
    uint64_t reversed_n = 0;

    // printf("Input an integer >= 0: ");
    if (scanf("%" SCNu32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    if (n < DEC_BASE)
    {
        printf("%" PRIu32, n);
        return EXIT_SUCCESS;
    }

    do
    {
        uint32_t digit = n % DEC_BASE;

        reversed_n = reversed_n * DEC_BASE + digit;

        n /= DEC_BASE;

    } while (n != 0);

    printf("%" PRIu64 "\n", reversed_n);

    return EXIT_SUCCESS;
}
