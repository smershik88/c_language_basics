#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Упаковать 0 и 1
Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей по следующему принципу: например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4] (т.к. начинается с нуля, то сразу записывается количество элементов первой серии); а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7] (т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).


Необходимо реализовать только одну функцию, всю программу загружать не надо. Прототип функции: int compression(int a[], int b[], int N)
Input format
Функция принимает исходный массив a[] и сжимает в массив b[], N - число элементов в массиве a[].
Output format
Функция возвращает число элементов сжатого массива b[]
Examples
Input
1 1 0 0 1 1 1 0 1 1 0 0 1 0 1 0 0 1 0 0 0 0 1 1 1 1 0 1 0 0 0 0 1 1 1 0 1 1 0 1 0 0 0 1 1 0 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 0 0 0 0 1 0 1 0 0 1 1 0 1 0 0 0 0 1 0 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 1 0 1 0 0
Output
[0,2,2,3,1,2,2,1,1,1,2,1,4,4,1,1,4,3,1,2,1,1,3,2,2,1,3,1,2,3,1,1,6,1,1,1,2,2,1,1,4,1,2,2,1,1,3,1,1,6,1,1,2]
Input
0 0 1 0 0 1 1 0 0 1 1 0 1 0 0 1 1 0 1 0 1 1 1 1 0 1 1 1 1 0 0 0 0 1 1 0 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 1 0 0 0 0 1 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 1 1 1 0 0 0 1 0 1 1 1 1 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1
Output
[2,1,2,2,2,2,1,1,2,2,1,1,1,4,1,4,4,2,2,1,1,1,1,3,1,1,1,2,1,3,4,1,1,1,3,1,1,5,1,1,1,3,3,1,1,4,1,3,2,4,1,1,1,2]
*/

void print_array(int a[], int size);
int compression(int a[], int b[], int N);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int array[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,};
    enum { array_size = sizeof array / sizeof *array };
    int array_compressed[array_size + 1] = {0};

    print_array(array, array_size);
    int count = compression(array, array_compressed, array_size);
    puts("");
    print_array(array_compressed, count);

    return EXIT_SUCCESS;
}

void print_array(int a[], int size)
{
    if (!a || size < 1)
        return;
    
    for (int a_index = 0; a_index < size; a_index++)
        printf("%d ", a[a_index]);    
}

int compression(int a[], int b[], int N)
{
    if (!a || !b || N <= 0)
        return 0;

    int b_index = 0;

    if (a[0] == 1)
        b[b_index++] = 0;

    
    for (int a_index = 0; a_index < N;)
    {
        int value = a[a_index];
        int count = 0;

        while (a_index < N && a[a_index] == value)
        {
            ++count;
            ++a_index;
        }

        b[b_index++] = count;
    }

    return b_index;
}
