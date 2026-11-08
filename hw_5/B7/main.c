#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Две одинаковые цифры
Ввести целое число и определить, верно ли, что в его записи есть  две одинаковые цифры, НЕ
обязательно стоящие рядом.

Формат входных данных
Одно целое число
Формат результата
Одно слово: YES или NO
Примеры
Входные данные
1234
Результат работы
NO
Входные данные
1242
Результат работы
YES
*/

#define DEC_BASE 10

int main(void)
{
    int32_t n = 0;

    if (scanf("%" SCNd32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    int64_t number = n;

    if (number < 0)
    {
        number = -number;
    }

    unsigned int digit_flags       = 0u;
    bool         double_digit_flag = false;

    while (number != 0)
    {
        const unsigned int digit = (unsigned int)(number % DEC_BASE);
        const unsigned int mask  = 1u << digit;

        if ((digit_flags & mask) != 0u)
        {
            double_digit_flag = true;
            break;
        }

        digit_flags |= mask;

        number /= DEC_BASE;
    }

    puts(double_digit_flag ? "YES" : "NO");

    return EXIT_SUCCESS;
}
