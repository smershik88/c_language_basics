#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Проверка на простоту
Проверить число на простоту.

Формат входных данных
Натуральное число
Формат результата
Если число является простым напечатать YES, иначе NO
Примеры
Входные данные
10
Результат работы
NO
Входные данные
7
Результат работы
YES
*/

int main(int argc, char* argv[])
{
    uint32_t n = 0;

    // printf("Input an one natural number: ");
    scanf("%" SCNu32, &n);

    if (!n)
        return EXIT_FAILURE;

    bool prime_flag = n == 1 ? false : true;

    for (uint32_t i = 2; i <= sqrt(n); i++)
    {
        if (n % i)
            continue;
        
        prime_flag = false;
        break;
    }

    printf("%s\n", prime_flag ? "YES" : "NO");   
    
    return EXIT_SUCCESS;
}