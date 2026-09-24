#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Наибольшее из двух чисел
Ввести два числа и вывести их в порядке возрастания.

Формат входных данных
Два целых числа

Формат результата
Два целых числа

Примеры
Входные данные
15 9
Результат работы
9 15
*/

int main(int argc, char* argv[])
{
    int32_t a = 0,
            b = 0;
    
    // printf("Input two integer numbers: ");
    scanf("%" SCNd32 " %" SCNd32, &a, &b);

    bool a_le_b = a <= b;

    printf("%" PRId32 " %" PRId32 "\n", 
        a_le_b ? a : b, 
        a_le_b ? b : a
    );

    return EXIT_SUCCESS;
}