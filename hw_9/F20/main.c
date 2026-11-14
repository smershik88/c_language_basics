#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
Четные и нечетные
Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел.
Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число на
произведение нечетных цифр в его десятичной записи. Если количество нечётных чисел больше или равно
количеству чётных, заменить каждое чётное число на произведение чётных цифр в его десятичной записи.

Input format
10 целых чисел через пробел
Output format
10 целых чисел через пробел
Examples
Input
48 31 20 61 97 12 18 100 200 123
Output
48 3 20 1 63 12 18 100 200 3
Input
48 25 57 34 23 91 90 85 30 79
Output
32 25 57 4 23 91 0 85 0 79
*/

#define ARRAY_SIZE 10
#define DEC_BASE   10

bool   array_fill(size_t size, int array[size]);
size_t count_odd(size_t size, const int array[size]);
int    prod_odd_digits(int n);
int    prod_even_digits(int n);
void   replace(size_t size, int array[size]);
void   array_print(size_t size, const int array[size]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int array[ARRAY_SIZE] = {0};

    if (!array_fill(ARRAY_SIZE, array))
    {
        return EXIT_FAILURE;
    }

    replace(ARRAY_SIZE, array);
    array_print(ARRAY_SIZE, array);

    return EXIT_SUCCESS;
}

bool array_fill(size_t size, int array[size])
{
    if (!array)
    {
        return false;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            return false;
        }
    }

    return true;
}

size_t count_odd(size_t size, const int array[size])
{
    size_t count = 0;

    if (!array)
    {
        return count;
    }

    for (size_t i = 0; i < size; i++)
    {
        if ((unsigned int)array[i] & 1U)
        {
            count++;
        }
    }
    return count;
}

int prod_odd_digits(int n)
{
    // printf("n = %d ", n);
    if (n == 0)
    {
        return 0;
    }

    int prod = 1;

    while (n)
    {
        int digit = n % DEC_BASE;
        if (digit < 0)
        {
            digit = -digit;
        }

        if ((unsigned int)digit & 1U)
        {
            prod *= digit;
        }

        n /= DEC_BASE;
    }

    // printf("prod = %d\n", prod);
    return prod;
}

int prod_even_digits(int n)
{
    // printf("n = %d ", n);
    if (n == 0)
    {
        return 0;
    }

    int prod = 1;

    while (n)
    {
        int digit = n % DEC_BASE;
        if (digit < 0)
        {
            digit = -digit;
        }

        if (((unsigned int)digit & 1U) == 0)
        {
            prod *= digit;
        }

        n /= DEC_BASE;
    }

    // printf("prod = %d\n", prod);
    return prod;
}

void replace(size_t size, int array[size])
{
    if (!array)
    {
        return;
    }

    size_t odd_count  = count_odd(size, array);
    size_t even_count = size - odd_count;

    if (even_count > odd_count)
    {
        for (size_t i = 0; i < size; i++)
        {
            if ((unsigned int)array[i] & 1U)
            {
                array[i] = prod_odd_digits(array[i]);
            }
        }
    }
    else
    {
        for (size_t i = 0; i < size; i++)
        {
            if ((unsigned int)array[i] & 1U)
            {
                continue;
            }
            array[i] = prod_even_digits(array[i]);
        }
    }
}

void array_print(size_t size, const int array[size])
{
    if (!array)
    {
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
