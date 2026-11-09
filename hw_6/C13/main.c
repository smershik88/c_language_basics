#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Вычислить cos
Составить функцию, которая вычисляет косинус как сумму ряда (с точностью 0.001)

cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... (x в радианах)

float cosinus(float x)
Формат входных данных
Целое число от 0 до 90
Формат результата
Вещественное число в формате "%.3f"
Примеры
Входные данные
60
Результат работы
0.500
*/

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define ALPHA_MIN 0
#define ALPHA_MAX 90
#define ERR       0.001
#define PI_RAD    180

double deg_to_rad(double deg);
double cos_taylor(double rad, double err);

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

    printf("%.3lf", cos_taylor(alpha, ERR));

    return EXIT_SUCCESS;
}

double deg_to_rad(double deg) { return deg * (M_PI / PI_RAD); }

double cos_taylor(double deg, double err)
{
    double rad = deg_to_rad(deg), term = 1, sum = 0;

    uint8_t n = 0;
    while (fabs(term) > err)
    {
        sum += term;
        term = term * (-rad * rad) / ((2 * n + 2) * (2 * n + 1));
        n++;
    }

    return sum;
}
