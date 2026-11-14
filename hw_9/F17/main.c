#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
След матрицы
Составить функцию которая находит след матрицы в двумерном массиве. Показать пример ее работы на
матрице из 5 на 5 элементов. След матрицы - это сумма элементов на главной диагонали.

Input format
25 целых чисел через пробел.
Output format
Одно целое число.
Examples
Input
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
Output
15
*/

#define SQUARE_MATRIX_SIZE 5

bool      matrix_fill(size_t rows, size_t cols, int matrix[rows][cols]);
long long get_trace(size_t size, const int matrix[size][size]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int matrix[SQUARE_MATRIX_SIZE][SQUARE_MATRIX_SIZE] = {0};

    if (!matrix_fill(SQUARE_MATRIX_SIZE, SQUARE_MATRIX_SIZE, matrix))
    {
        return EXIT_FAILURE;
    }

    printf("%lld", get_trace(SQUARE_MATRIX_SIZE, (const int (*)[SQUARE_MATRIX_SIZE])matrix));

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

long long get_trace(size_t size, const int matrix[size][size])
{
    long long trace = 0;

    if (!matrix)
    {
        return trace;
    }

    for (size_t i = 0; i < size; i++)
    {
        trace += matrix[i][i];
    }

    return trace;
}
