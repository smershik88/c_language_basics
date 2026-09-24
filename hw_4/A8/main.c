#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Наибольшее из трех чисел
Ввести три числа и найти наибольшее из них

Формат входных данных
Три целых числа через пробел

Формат результата
Одно наибольшее целое число

Примеры
Входные данные
4 15 9
Результат работы
15
*/

#define MAX_3(a, b, c) (a >= b ? (a >= c ? a : c) : (b >= c ? b : c))

int main(int argc, char* argv[])
{
    int32_t a = 0,
            b = 0,
            c = 0;
    
    // printf("Input three integer numbers: ");
    scanf("%" SCNd32 " %" SCNd32" %" SCNd32, &a, &b, &c);

    printf("%" PRId32 "\n", MAX_3(a, b, c));

    return EXIT_SUCCESS;
}