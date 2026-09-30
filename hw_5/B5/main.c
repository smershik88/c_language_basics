#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[])
{
    int32_t n = 0;
    uint8_t digits_sum = 0;

    // printf("Input an integer >= 0: ");
    scanf("%" SCNd32, &n);

    if (n < 0)
        return EXIT_FAILURE;

    while (n)
    {
        digits_sum += (uint8_t)(n % 10);
        n = n / 10;
    }

    printf("%" PRIu8 "\n", digits_sum);

    return EXIT_SUCCESS;
}