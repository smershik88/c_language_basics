#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сумма квадратов маленьких чисел
Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.

Формат входных данных
Два целых числа по модулю не больше 100
Формат результата
Сумма квадратов от первого введенного числа до второго
Примеры
Входные данные
4 10
Результат работы
371
Входные данные
1 5
Результат работы
55
*/

int main(int argc, char* argv[])
{
    int8_t  a = 0,
            b = 0;

    // printf("Enter two integers a and b whose absolute value does not exceed 100 and a <= b: ");
    scanf("%" SCNd8 " %" SCNd8 , &a, &b);

    if (a > b || abs(a) > 100 || abs(b) > 100)
        return EXIT_FAILURE;

    uint32_t sumOfSquares = 0;

    for (; a <= b; a++)
        sumOfSquares += (uint32_t)(a * a);

    printf("%" PRIu32 " ", sumOfSquares);

    return EXIT_SUCCESS;
}