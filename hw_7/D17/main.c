#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Функция Аккермана
Функция Аккермана определяется рекурсивно для неотрицательных целых чисел m и n следующим образом:

Реализуйте данную функцию по прототипу
int akkerman(int m, int n)

Формат входных данных
Даны неотрицательные целые числа m и n
Формат результата
Одно целое число
Примеры
Входные данные
2 1
Результат работы
5
Входные данные
2 4
Результат работы
11
*/

uint64_t akkerman(uint32_t m, uint64_t n);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t m = 0,
             n = 0;

    scanf("%" SCNu32 " %" SCNu32, &m, &n);

    printf("%" PRIu64, akkerman(m, n));
    
    return EXIT_SUCCESS;
}

uint64_t akkerman(uint32_t n, uint64_t m)
{
    if (n == 0)
        return m + 1;
    
    if (m == 0)
        return akkerman(n - 1, 1);

    return akkerman(n - 1, akkerman(n, m - 1));
}
