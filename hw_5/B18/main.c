#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Числа Фибоначчи
Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.
Числа Фибоначчи – это элементы числовой последовательности 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …, в которой каждое последующее число равно сумме двух предыдущих.

Формат входных данных
Одно натуральное число
Формат результата
Ряд чисел Фибоначчи через пробел
Примеры
Входные данные
5
Результат работы
1 1 2 3 5
Входные данные
10
Результат работы
1 1 2 3 5 8 13 21 34 55
*/

int main(int argc, char* argv[])
{
    uint32_t n = 0;
    uint32_t fib_prev = 1,
             fib_2nd_to_prev = 1;
    
    // printf("Input an one natural number: ");
    scanf("%" SCNu32, &n);

    if (!n)
        return EXIT_FAILURE;
    
    printf("1");
    
    if (n == 1)
        return EXIT_SUCCESS;

    printf(" 1");

    for (uint32_t i = 2; i < n; i++)
    {
        uint32_t s_two_prev = fib_prev + fib_2nd_to_prev;
        fib_2nd_to_prev = fib_prev;
        fib_prev = s_two_prev;

        printf(" %" PRIu32, s_two_prev);
    }
    
    return EXIT_SUCCESS;
}