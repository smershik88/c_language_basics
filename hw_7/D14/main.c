#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Все нечетные
Дана последовательность целых чисел через пробел, завершающаяся числом 0. Выведите все нечетные числа из этой последовательности, сохраняя их порядок.

Формат входных данных
Последовательность не нулевых целых чисел. В конце число 0.
Формат результата
Введенная последовательность, кроме четных чисел в том же порядке. Число 0 не выводить.
Примеры
Входные данные
12 13 173 28 19 0
Результат работы
13 173 19
*/

void print_odd_input();

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    print_odd_input();
    
    return EXIT_SUCCESS;
}

void print_odd_input()
{
    int32_t n = 0;

    scanf("%" SCNd32, &n);

    if (n == 0)
        return;

    if (n % 2)
        printf("%" PRId32 " ", n);

    print_odd_input();
}
