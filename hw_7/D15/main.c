#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Найти наибольшее
Дана последовательность ненулевых целых чисел, завершающаяся числом 0. Ноль в последовательность не входит. Определите наибольшее значение числа в этой последовательности. Для решения задачи необходимо написать рекурсивную функцию вида:
int max_find(int max)

Формат входных данных
Последовательность не нулевых целых чисел. В конце последовательности число 0.
Формат результата
Одно число. Максимум последовательности.
Примеры
Входные данные
1 12 2 5 8 0
Результат работы
12
*/

int32_t max_find(int32_t max);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    printf("%" PRId32, max_find(INT32_MIN));
    
    return EXIT_SUCCESS;
}

int32_t max_find(int32_t max)
{
    
    int32_t n = 0;

    scanf("%" SCNd32, &n);

    if (n == 0)
        return max;

    if (n > max)
    {
        max = n;
    }

    return max_find(max);
}
