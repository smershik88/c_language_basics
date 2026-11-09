#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Все цифры в порядке возрастания
Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.

Формат входных данных
Целое число
Формат результата
YES или NO
Примеры
Входные данные
1238
Результат работы
YES
Входные данные
1274
Результат работы
NO
*/

#define DEC_BASE 10

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int32_t n      = 0;
    bool    result = true;

    // printf("Input an integer: ");
    if (scanf("%" SCNd32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    n = abs(n);

    uint8_t prev_digit = (uint8_t)(n % DEC_BASE);
    n /= DEC_BASE;

    while (n)
    {
        uint8_t digit = (uint8_t)(n % DEC_BASE);
        n /= DEC_BASE;
        if (digit >= prev_digit)
        {
            result = false;
            break;
        }
    }

    puts(result ? "YES" : "NO");

    return EXIT_SUCCESS;
}
