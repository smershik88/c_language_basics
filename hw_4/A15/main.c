#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Уравнение прямой
Определить уравнение прямой по координатам двух точек. Уравнение вида

y=k*x+b
Формат входных данных
Четыре целых числа через пробел. Координаты X1 Y1 X2 Y2
Формат результата
Два числа K,B в формате "%.2f %.2f"
Примеры
Входные данные
6 9 -1 3
Результат работы
0.86 3.86
Входные данные
1 2 3 4
Результат работы
1.00 1.00
*/

int main(int argc, char* argv[])
{
    int32_t x1 = 0,
        y1 = 0,
        x2 = 0,
        y2 = 0;

    // printf("Input x1 y1 x2 y2 as integer numbers: ");
    scanf("%" SCNd32 " %" SCNd32 " %" SCNd32 " %" SCNd32, &x1, &y1, &x2, &y2);

    /*
        y1 = k * x1 + b     b = y1 - k * x1                 b = y1 - k * x1
        |                   |                               |
        y2 = k * x2 + b     y2 = k * x2 + y1 - k * x1       k = (y2 - y1) / (x2 - x1)
    */

    if (x2 - x1 == 0)
        return EXIT_FAILURE;

    double k = (double)(y2 - y1) / (x2 - x1);
    double b = y1 - k * x1;

    printf("%.2f %.2f\n", k, b);


    return EXIT_SUCCESS;
}