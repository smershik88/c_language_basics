#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма цифр равна 10
Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.

Формат входных данных
Натуральное число
Формат результата
YES или NO
Примеры
Входные данные
1234
Результат работы
YES
Входные данные
1233
Результат работы
NO
*/

#define DEC_BASE 10
#define SUM      10

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0, s = 0;

    // printf("Input an one natural number: ");
    if (scanf("%" SCNu32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    while (n)
    {
        uint8_t digit = (uint8_t)(n % DEC_BASE);
        n /= DEC_BASE;

        s += digit;
    }

    printf("%s\n", s == SUM ? "YES" : "NO");

    return EXIT_SUCCESS;
}
