#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Вычислить sin
Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)

sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)

float sinus(float x)
Формат входных данных
Одно число от 0 до 90
Формат результата
Вещественное число в формате "%.3f"
Примеры
Входные данные
45
Результат работы
0.707
*/

double deg_to_rad(double deg);
double sin_taylor(double rad, double err);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    double alpha = 0;

    scanf("%lf", &alpha);

    if (alpha < 0 || alpha > 90)
        return EXIT_FAILURE;

    printf("%.3lf", sin_taylor(alpha, 0.001));

    return EXIT_SUCCESS;
}

double deg_to_rad(double deg)
{
    return deg * (M_PI / 180);
}

double sin_taylor(double deg, double err)
{
    double  rad = deg_to_rad(deg),
            term = rad,
            sum = 0;
    
    uint8_t n = 1;
    while(fabs(term) > err)
    {
        sum += term;
        term = term * (-rad * rad) / ((2 * n) * (2 * n + 1));
        n++;
    }

    return sum;
}
