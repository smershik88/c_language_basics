#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Больше среднего
Определить количество положительных элементов квадратной матрицы, превышающих по величине среднее
арифметическое всех элементов главной диагонали. Реализовать функцию среднее арифметическое главной
диагонали.

Input format
5 строк по 5 целых чисел через пробел
Output format
Одно целое число
Examples
Input
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
Output
10
*/

#define SQUARE_MATRIX_SIZE 5

bool        matrix_fill(size_t rows, size_t cols, int matrix[rows][cols]);
long double get_main_diagonal_avg(size_t size, const int matrix[size][size]);
size_t      count_positive_above_diagonal_avg(size_t size, const int matrix[size][size]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int matrix[SQUARE_MATRIX_SIZE][SQUARE_MATRIX_SIZE] = {0};

    if (!matrix_fill(SQUARE_MATRIX_SIZE, SQUARE_MATRIX_SIZE, matrix))
    {
        return EXIT_FAILURE;
    }

    printf("%zu", count_positive_above_diagonal_avg(SQUARE_MATRIX_SIZE,
                                                    (const int (*)[SQUARE_MATRIX_SIZE])matrix));

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

long double get_main_diagonal_avg(size_t size, const int matrix[size][size])
{
    long double avg = 0;

    if (!matrix)
    {
        return avg;
    }

    long long sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[i][i];
    }

    avg = sum / (long double)size;
    return avg;
}

size_t count_positive_above_diagonal_avg(size_t size, const int matrix[size][size])
{
    size_t count = 0;

    if (!matrix)
    {
        return count;
    }

    long double avg = get_main_diagonal_avg(size, matrix);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] > 0 && matrix[i][j] > avg)
            {
                count++;
            }
        }
    }

    return count;
}
