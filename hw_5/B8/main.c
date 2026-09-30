#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Ровно одна цифра 9
Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».

Формат входных данных
Одно целое число
Формат результата
Ответ: YES или NO
Примеры
Входные данные
193
Результат работы
YES
Входные данные
1994
Результат работы
NO
*/

int main(int argc, char* argv[])
{
    int32_t n = 0;
    uint8_t nine_counter = 0;
    
    // printf("Input an integer: ");
    scanf("%" SCNd32, &n);
    
    n = abs(n);
    
    while (n)
    {
        uint8_t digit = (uint8_t)(n % 10);
        n = n / 10;
        if (digit == 9)
            nine_counter++;
    }

    puts(nine_counter == 1 ? "YES" : "NO");

    return EXIT_SUCCESS;
}