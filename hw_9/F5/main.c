#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Максимум в массиве
Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
Прототип функции: int find_max_array(int size, int a[])

Input format
Массив состоящий из целых чисел. Первый аргумент, размер массива, второй аргумент адрес нулевого элемента.
Output format
Одно целое число
Examples
Input
773 307 371 548 531 765 402 27 573 591 217 859 662 493 173 174 125 591 324 231 130 394 573 65 570 258 343 3 586 14 785 296 140 726 598 262 807 794 510 465 66 895 182 218 302 34 205 252 687 660 952 737 2 32 310 680 36 139 346 139 489 217 767 544 158 774 883 154 802 136 569 377 867 423 224 176 118 660 513 734 45 978 983 749 909 601 270 147 433 737 789 304 842 769 815 503 190 399 3
Output
983
*/

int find_max_array(int size, int a[]);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int array[] = {-1, 0, 1, 2, 3, 4, 5};

    printf("%d", find_max_array(sizeof array / sizeof *array, array));

    return EXIT_SUCCESS;
}

int find_max_array(int size, int a[])
{
    if (!a || size < 1)
        return 0;

    int max = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
 
    return max;
}
