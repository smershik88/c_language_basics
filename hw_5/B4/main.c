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

int main(int argc, char* argv[])
{
    int32_t n = 0;
    uint8_t d = 0;

    // printf("Enter an integer number: ");
    scanf("%" SCNd32, &n);

    n = abs(n);

    while (n)
    {
        n /= 10;
        d++;
    }

    printf("%s\n", d == 3 ? "YES" : "NO");

    return EXIT_SUCCESS;
}