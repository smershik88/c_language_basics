#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Все цифры в порядке возрастания
Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.

Формат входных данных
Целое число
Формат результата
YES или NO
Примеры
Входные данные
1238
Результат работы
YES
Входные данные
1274
Результат работы
NO
*/

int main(int argc, char* argv[])
{
    int32_t n = 0;
    bool result = true;
    
    // printf("Input an integer: ");
    scanf("%" SCNd32, &n);
    
    n = abs(n);
    
    uint8_t prev_digit = (uint8_t)(n % 10);
    n /= 10;

    while (n)
    {
        uint8_t digit = (uint8_t)(n % 10);
        n /= 10;
        if (digit >= prev_digit)
        {
            result = false;
            break;
        }
    }

    puts(result ? "YES" : "NO");

    return EXIT_SUCCESS;
}