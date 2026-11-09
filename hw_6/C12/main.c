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

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define ALPHA_MIN 0
#define ALPHA_MAX 90
#define ERR       0.001
#define PI_RAD    180

double deg_to_rad(double deg);
double sin_taylor(double rad, double err);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    double alpha = 0;

    if (scanf("%lf", &alpha) != 1)
    {
        return EXIT_FAILURE;
    }

    if (alpha < ALPHA_MIN || alpha > ALPHA_MAX)
    {
        return EXIT_FAILURE;
    }

    printf("%.3lf", sin_taylor(alpha, ERR));

    return EXIT_SUCCESS;
}

double deg_to_rad(double deg) { return deg * (M_PI / PI_RAD); }

double sin_taylor(double deg, double err)
{
    double rad = deg_to_rad(deg), term = rad, sum = 0;

    uint8_t n = 1;
    while (fabs(term) > err)
    {
        sum += term;
        term = term * (-rad * rad) / ((2 * n) * (2 * n + 1));
        n++;
    }

    return sum;
}
