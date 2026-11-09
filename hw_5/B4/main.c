#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Ровно три цифры
Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.

Формат входных данных
Целое положительное число
Формат результата
Одно слов: YES или NO
Примеры
Входные данные
123
Результат работы
YES
Входные данные
1234
Результат работы
NO
*/

#define DEC_BASE 10

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int32_t n = 0;
    uint8_t d = 0;

    // printf("Enter an integer number: ");
    if (scanf("%" SCNd32, &n) != 1)
    {
        return EXIT_FAILURE;
    }

    n = abs(n);

    while (n)
    {
        n /= DEC_BASE;
        d++;
    }

    printf("%s\n", d == 3 ? "YES" : "NO");

    return EXIT_SUCCESS;
}
