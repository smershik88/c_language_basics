#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Массив максимумов
Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм вычисления суммы максимальных
элементов из каждой строки. Напечатать значение этой суммы. Предполагается, что в каждой строке
такой элемент единственный. Реализовать функцию поиска максимума в строке из 10 элементов

Input format
10 строк состоящих из 10 целых чисел через пробел.
Output format
Одно целое число
Examples
Input
61 75 55 2 35 34 77 93 28 49
11 34 22 78 19 14 67 67 11 0
72 39 23 53 92 51 60 34 71 63
14 27 72 6 0 79 98 56 30 15
31 16 3 4 95 59 25 17 11 20
5 93 21 61 96 30 79 38 73 40
89 4 66 19 36 99 67 67 92 36
87 54 7 35 40 43 44 46 4 69
98 57 20 75 9 66 85 9 39 31
8 90 94 25 12 30 18 10 23 15
Output
930
*/

#define NUMBER_OF_ROWS 10
#define NUMBER_OF_COLS 10

bool      matrix_fill(size_t rows, size_t cols, int matrix[rows][cols]);
int       get_max(size_t size, const int array[size]);
long long get_sum_of_max(size_t rows, size_t cols, const int matrix[rows][cols]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int matrix[NUMBER_OF_ROWS][NUMBER_OF_COLS] = {0};

    if (!matrix_fill(NUMBER_OF_ROWS, NUMBER_OF_COLS, matrix))
    {
        return EXIT_FAILURE;
    }

    printf("%lld",
           get_sum_of_max(NUMBER_OF_ROWS, NUMBER_OF_COLS, (const int (*)[NUMBER_OF_COLS])matrix));

    return EXIT_SUCCESS;
}

bool matrix_fill(size_t rows, size_t cols, int matrix[rows][cols])
{
    if (!matrix)
    {
        return false;
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                return false;
            }
        }
    }

    return true;
}

int get_max(size_t size, const int array[size])
{
    int max = INT_MIN;

    if (!array)
    {
        return max;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

long long get_sum_of_max(size_t rows, size_t cols, const int matrix[rows][cols])
{
    long long sum = 0;

    if (!matrix)
    {
        return sum;
    }

    for (size_t i = 0; i < rows; i++)
    {
        sum += get_max(cols, matrix[i]);
    }

    return sum;
}
