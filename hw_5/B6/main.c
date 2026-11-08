#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Две одинаковые цифры рядом
Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие
рядом.

Формат входных данных
Одно целое число
Формат результата
Единственное слов: YES или NO
Примеры
Входные данные
1232
Результат работы
NO
Входные данные
1224
Результат работы
YES
*/

#define DEC_BASE 10

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int32_t n = 0;

    // printf("Input an integer >= 0: ");
    if (scanf("%" SCNd32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    n = abs(n);

    bool    double_digit_flag = false;
    uint8_t prev_digit        = (uint8_t)(n % DEC_BASE);
    n /= DEC_BASE;

    while (n)
    {
        uint8_t digit = (uint8_t)(n % DEC_BASE);
        if (digit == prev_digit)
        {
            double_digit_flag = true;
            break;
        }
        n          = n / DEC_BASE;
        prev_digit = digit;
    }

    puts(double_digit_flag ? "YES" : "NO");

    return EXIT_SUCCESS;
}
