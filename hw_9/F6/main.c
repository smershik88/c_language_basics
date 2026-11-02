#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Два одинаковых
Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
int is_two_same(int size, int a[]);

Input format
Массив из целых чисел
Output format
Функция возвращает 1 или 0
Examples
Input
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
Output
NO
Input
1 2 1 4 5
Output
YES
*/

int is_two_same(int size, int a[]);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int array[] = {1, 2, 7, 9, 5};

    puts(is_two_same(sizeof array / sizeof *array, array) == 1 ? "YES" : "NO");

    return EXIT_SUCCESS;
}

int is_two_same(int size, int a[])
{
    if (!a || size < 2)
        return 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] == a[j])
                return 1;
        } 
    }
    
    return 0;
}
