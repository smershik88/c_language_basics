#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Все счастливые числа
Ввести натурально число и напечатать все числа от 10 до введенного числа - у которых сумма цифр
равна произведению цифр

Формат входных данных
Одно натуральное число большее 10
Формат результата
Числа у которых сумма цифр равна произведению цифр через пробел в порядке возрастания. Не
превосходящие введенное число. Примеры Входные данные 200 Результат работы 22 123 132 Входные данные
1000
Результат работы
22 123 132 213 231 312 321
Входные данные
22
Результат работы
22
*/

#define MIN      10
#define DEC_BASE 10

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    // printf("Input an one natural number > 10: ");
    if (scanf("%" SCNu32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    if (n <= MIN)
    {
        return EXIT_FAILURE;
    }

    for (uint32_t i = MIN; i <= n; i++)
    {
        uint32_t t = i;
        uint32_t s = 0, p = 1;

        while (t)
        {
            uint8_t digit = (uint8_t)(t % DEC_BASE);
            t /= DEC_BASE;

            s += digit;
            p *= digit;
        }

        if (s == p)
        {
            printf("%" PRIu32 " ", i);
        }
    }

    return EXIT_SUCCESS;
}
