#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Цифры по возрастанию
Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры
стоят по возрастанию. Используя данную функцию решить задачу. int grow_up(int n)

Формат входных данных
Одно целое не отрицательное число
Формат результата
YES или NO
Примеры
Входные данные
258
Результат работы
YES
Входные данные
528
Результат работы
NO
*/

#define DEC_BASE 10

bool grow_up(uint32_t n);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    if (scanf("%" SCNu32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    printf("%s", grow_up(n) ? "YES" : "NO");

    return EXIT_SUCCESS;
}

bool grow_up(uint32_t n)
{
    uint8_t prev_digit = (uint8_t)(n % DEC_BASE);
    n /= DEC_BASE;

    while (n)
    {
        uint8_t digit = (uint8_t)(n % DEC_BASE);
        n /= DEC_BASE;
        if (digit >= prev_digit)
        {
            return false;
        }
        prev_digit = digit;
    }

    return true;
}
