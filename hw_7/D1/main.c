#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
От 1 до N
Составить рекурсивную функцию, печать всех чисел от 1 до N

Формат входных данных
Одно натуральное число
Формат результата
Последовательность чисел от 1 до введенного числа
Примеры
Входные данные
5
Результат работы
1 2 3 4 5
*/

void print_to_n(uint32_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t n = 0;

    scanf("%" SCNu32, &n);
    print_to_n(n);
    
    return EXIT_SUCCESS;
}

void print_to_n(uint32_t n)
{
    if (n == 0)
        return;

    print_to_n(n - 1);

    printf("%" PRIu32 " ", n);
}