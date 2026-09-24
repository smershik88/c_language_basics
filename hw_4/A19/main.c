#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Существует ли треугольник
Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.

Формат входных данных
Три целых числа. Стороны треугольника a, b, c.
Формат результата
YES или NO
Примеры
Входные данные
3 2 4
Результат работы
YES
*/

int main(int argc, char* argv[])
{
    int32_t a = 0,
            b = 0,
            c = 0;

    // printf("Input three side's lenghts of triangle as integer numbers: ");
    scanf("%" SCNd32 " %" SCNd32 " %" SCNd32, &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0)
    {
        puts("NO");
        return EXIT_SUCCESS;
    }

    if (a + b > c && a + c > b && b + c > a)
        puts("YES");
    else
        puts("NO");

    return EXIT_SUCCESS;
}