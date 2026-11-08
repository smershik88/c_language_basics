#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Четные в начало
Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все
нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:. void
sort_even_odd(int n, int a[])

Input format
Функцийя принмате на вход целые числа
Output format
Отсортированный исходный массив
Examples
Input
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Output
20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1
Input
1 0 1 0 1
Output
0 0 1 1 1
*/

void print_array(int a[], int size);
void sort_even_odd(int n, int a[]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int array[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    int size    = sizeof array / sizeof array[0];
    print_array(array, size);
    puts("");
    sort_even_odd(size, array);
    print_array(array, size);

    return EXIT_SUCCESS;
}

void print_array(int a[], int size)
{
    if (!a || size < 1)
        return;

    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
}

void sort_even_odd(int n, int a[])
{
    if (!a || n < 2)
        return;

    for (int i = 1; i < n; i++)
    {
        for (int j = i;
             j > 0 && ((unsigned int)a[j] & 1U) == 0 && ((unsigned int)a[j - 1] & 1U) == 1; j--)
        {
            int tmp  = a[j];
            a[j]     = a[j - 1];
            a[j - 1] = tmp;
        }
    }
}
