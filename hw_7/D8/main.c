#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
От A до B
Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.

Input format
Два целых числа через пробел.
Output format
Последовательность целых чисел.
Examples
Input
5 2
Output
5 4 3 2
Input
2 7
Output
2 3 4 5 6 7
*/

void print_ab_range(int32_t a, int32_t b);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    int32_t a = 0,
            b = 0;

    scanf("%" SCNd32 " %" SCNd32, &a, &b);
    print_ab_range(a, b);
    
    return EXIT_SUCCESS;
}

void print_ab_range(int32_t a, int32_t b)
{
    if (a == b)
    {
        printf("%" PRId32 " ", a);
        return;
    }

    printf("%" PRId32 " ", a);

    print_ab_range((a < b ? a + 1 : a - 1), b);
}