#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/*
Перевести число N в систему счисления P
Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.

Input format
Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9
Output format
Одно целое число
Examples
Input
25 5
Output
100
Input
9 2
Output
1001
Input
11 3
Output
102
*/

uint64_t convert_n_to_base_p(uint32_t n, uint8_t p);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    uint32_t n = 0;
    uint8_t p = 0;

    scanf("%" SCNu32 " %" SCNu8, &n, &p);

    if (p < 2 || p > 9)
        return EXIT_FAILURE;
    
    printf("%" PRIu64, convert_n_to_base_p(n, p));

    return EXIT_SUCCESS;
}

uint64_t convert_n_to_base_p(uint32_t n, uint8_t p)
{
    uint64_t number = 0;
    uint64_t position = 1; 
    while(n)
    {
        uint8_t digit = (uint8_t)(n % p);
        n /= p; 
        number += digit * position;
        position *= 10;
    }
    return number;
}