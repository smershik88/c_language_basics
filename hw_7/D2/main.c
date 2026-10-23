#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма чисел от 1 до N
Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N

Формат входных данных
Одно натуральное число
Формат результата
Сумма чисел от 1 до введенного числа
Примеры
Входные данные
5
Результат работы
15
Входные данные
100
Результат работы
5050
*/

uint64_t sum_to_n(uint32_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);
    printf("%" PRIu64, sum_to_n(n));
    
    return EXIT_SUCCESS;
}

uint64_t sum_to_n(uint32_t n)
{
    if (n == 1)
        return 1; 
    
    return n + sum_to_n(n - 1);
}
