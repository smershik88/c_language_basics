#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Сортировка по взрастанию
Написать только одну функцию, которая сортирует массив по возрастанию. Необходимо реализовать только одну функцию, всю программу составлять не надо.
Строго согласно прототипу. Имя функции и все аргументы должны быть: void sort_array(int size, int a[]).
Всю программу загружать не надо, только одну эту функцию. Можно просто закомментировать текст всей программы, кроме данной функции.

Input format
Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента.
Output format
Функция ничего не возвращает. Производит сортировку переданного ей массива по возрастанию.
Examples
Input
20 19 4 3 2 1 18 17 13 12 11 16 15 14 10 9 8 7 6 5
Output
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
Input
5 4 3 2 1
Output
1 2 3 4 5
*/

void print_array(int a[], int size);
void sort_array(int size, int a[]);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int array[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    int size = sizeof array / sizeof array[0];
    print_array(array, size);
    puts("");
    sort_array(size, array);
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

void sort_array(int size, int a[])
{
    if (!a || size < 2)
        return;

    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--)
        {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
        }
    }
}