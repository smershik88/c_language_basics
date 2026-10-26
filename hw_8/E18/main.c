#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Кратность прежде всего
В диапазоне натуральных чисел от 2 до N определить, сколько из них кратны любому из чисел в диапазоне от 2 до 9.

Input format
Одно целое число N большее 2 и не превосходящее 10000
Output format
Все числа от 2 до 9 в формате: 2 количество чисел кратных 2 3 количество чисел кратных 3 4 количество чисел кратных 4 5 количество чисел кратных 5 6 количество чисел кратных 6 7 количество чисел кратных 7 8 количество чисел кратных 8 9 количество чисел кратных 9
Examples
Input
99
Output
2  49
3  33
4  24
5  19
6  16
7  14
8  12
9  11
Input
9
Output
2 4
3 3
4 2
5 1
6 1
7 1
8 1
9 1
*/

#define START 2U
#define END 9U
#define MIN 2U
#define MAX 10000U

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    uint16_t n = 0;

    if (scanf("%" SCNu16, &n) != 1 || n < MIN || n > MAX)
        return EXIT_FAILURE;

    for (size_t i = START; i <= END; i++)
        printf("%zu" " %zu\n", i, n / i);
    
    return EXIT_SUCCESS;
}
