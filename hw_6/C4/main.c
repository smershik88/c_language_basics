#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Функция по формуле
Описать функцию вычисления f(x) по формуле:
f(x)= x*x при -2 ≤ x < 2;
x*x+4x+5 при x ≥ 2;
4 при x < -2.
Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.

Формат входных данных
Последовательность не нулевых целых чисел, в конце последовательности число 0.
Формат результата
Одно целое число
Примеры
Входные данные
8 3 -3 10 0
Результат работы
145
Входные данные
-2 -1 -3 1 0
Результат работы
4
*/

int32_t calc_func(int32_t x);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    int32_t n = 0,
            max = INT32_MIN;

    do
    {
        if (scanf("%" SCNd32, &n) != 1 || n == 0)
            break;

        int32_t result = calc_func(n);
        // printf("%" PRId32 "\n", result);
        
        max = result > max ? result : max;
    } while (true);
    
    printf("%" PRId32, max);
    
    return EXIT_SUCCESS;
}

int32_t calc_func(int32_t x)
{
    if (x >= -2 && x < 2 )
        return x * x;
    else if (x >= 2)
        return x * x + 4 * x + 5;
    else // x < -2
        return 4;    
}
