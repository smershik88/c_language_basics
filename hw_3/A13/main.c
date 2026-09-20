#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int number = 0;
    unsigned int digits_prod = 1;

    // printf("Input integer number: ");
    scanf("%d", &number);

    number = abs(number);

    while (number)
    {
        digits_prod *= number % 10;
        number = number / 10;
    }

    printf("%d\n", digits_prod);

    return EXIT_SUCCESS;
}