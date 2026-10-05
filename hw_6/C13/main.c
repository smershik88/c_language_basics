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

double deg_to_rad(double deg);
double cos_taylor(double rad, double err);

int main(int argc, char* argv[])
{
    double alpha = 0;

    scanf("%lf", &alpha);

    if (alpha < 0 || alpha > 90)
        return EXIT_FAILURE;

    printf("%.3lf", cos_taylor(alpha, 0.001));

    return EXIT_SUCCESS;
}

double deg_to_rad(double deg)
{
    return deg * (M_PI / 180);
}

double cos_taylor(double deg, double err)
{
    double  rad = deg_to_rad(deg),
            term = 1,
            sum = 0;
    
    uint8_t n = 0;
    while(fabs(term) > err)
    {
        sum += term;
        term = term * (-rad * rad) / ((2 * n + 2) * (2 * n + 1));
        n++;
    }

    return sum;
}
