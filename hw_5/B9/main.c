#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Все цифры четные
Ввести целое число и определить, верно ли, что все его цифры четные.

Формат входных данных
Одно целое число
Формат результата
YES или NO
Примеры
Входные данные
2684
Результат работы
YES
Входные данные
2994
Результат работы
NO
*/

int main(int argc, char* argv[])
{
    int32_t n = 0;
    bool odd_flag = false;
    
    // printf("Input an integer: ");
    scanf("%" SCNd32, &n);
    
    n = abs(n);
    
    while (n)
    {
        uint8_t digit = (uint8_t)(n % 10);
        n = n / 10;
        if (digit & 1U)
        {
            odd_flag = true;
            break;
        }
    }

    // is even?
    puts(odd_flag ? "NO" : "YES");

    return EXIT_SUCCESS;
}