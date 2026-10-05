#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Проверка на простоту
Составить функцию логическую функцию, которая определяет, верно ли, что число простое. Используя функцию решить задачу. int is_prime(int n)

Формат входных данных
Одно целое не отрицательное число.
Формат результата
YES или NO
Примеры
Входные данные
13
Результат работы
YES
Входные данные
136
Результат работы
NO
*/

bool is_prime (uint32_t n);

int main(int argc, char* argv[])
{
    uint32_t n = 0 ;

    scanf("%" SCNu32, &n);
    printf("%s", is_prime(n) ? "YES" : "NO");

    return EXIT_SUCCESS;
}

bool is_prime(uint32_t n)
{
    bool prime_flag = n < 2 ? false : true;

    for (uint32_t i = 2; i <= sqrt(n); i++)
    {
        if (n % i)
            continue;
        
        prime_flag = false;
        break;
    }

    return prime_flag;
}
