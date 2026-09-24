#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Максимальная цифра
Дано трехзначное число, напечатать макисмальную цифру

Формат входных данных
Целое положительное трехзначное число
Формат результата
Одна цифра
Примеры
Входные данные
435
Результат работы
5
*/

static size_t get_number_of_digits(int64_t n);
static void get_digits(int64_t n, uint8_t *const digits_array, size_t digits_array_size);
static uint8_t max(const uint8_t *const array, size_t array_size);

int main(int argc, char* argv[])
{
    int64_t number = 0;

    // printf("Input integer number: ");
    scanf("%" SCNd64, &number);

    const size_t number_of_digits = get_number_of_digits(number);
    uint8_t digits_array[number_of_digits];

    get_digits(number, digits_array, number_of_digits);

    printf("%" PRId8, max(digits_array, number_of_digits));

    return EXIT_SUCCESS;
}

static size_t get_number_of_digits(const int64_t n){
    size_t result = 1;
    
    if (n == 0)
        return result;
        
    int64_t n_abs = llabs(n);
    result = (size_t)log10l(n_abs) + 1;
    return result;
}

static void get_digits(int64_t n, uint8_t *const digits_array, size_t digits_array_size)
{
    if (digits_array == NULL || digits_array_size == 0)
        return;

    for (size_t i = 0; i < digits_array_size; i++)
    {
        digits_array[i] = (uint8_t)(n % 10);
        n /= 10;
    }
}

static uint8_t max(const uint8_t *const array, size_t array_size)
{
    uint8_t result = 0;

    if (array == NULL || array_size == 0)
        return result;
    
    for (size_t i = 0; i < array_size; i++)
    {
        result = array[i] >= result ? array[i] : result;
    } 

    return result;
}
