#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Ровно одна цифра 9
Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».

Формат входных данных
Одно целое число
Формат результата
Ответ: YES или NO
Примеры
Входные данные
193
Результат работы
YES
Входные данные
1994
Результат работы
NO
*/

#define DEC_BASE       10
#define REQUIRED_DIGIT 9

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int32_t n       = 0;
    uint8_t counter = 0;

    // printf("Input an integer: ");
    if (scanf("%" SCNd32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    n = abs(n);

    while (n)
    {
        uint8_t digit = (uint8_t)(n % DEC_BASE);
        n             = n / DEC_BASE;
        if (digit == REQUIRED_DIGIT)
        {
            counter++;
        }
    }

    puts(counter == 1 ? "YES" : "NO");

    return EXIT_SUCCESS;
}
