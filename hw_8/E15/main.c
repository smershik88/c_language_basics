#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.

Input format
10 целых чисел через пробел.
Output format
Сперва положительные числа, потом отрицательыне числа, через пробел.
Examples
Input
5 -4 0 1 4 -3 -3 3 0 2
Output
5 1 4 3 2 -4 -3 -3
*/

#define SIZE 10U

bool read_array(int32_t *array, size_t n);
void print_array(const int32_t *array, size_t n);
bool is_neg(int32_t n);
bool is_pos(int32_t n);
size_t filter_array(const int32_t *src_array, size_t src_array_size,
    int32_t* dest_array, size_t dest_array_size, bool (*predicate)(int32_t)
);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    int32_t array[SIZE] = {0};
    int32_t pos_array[SIZE] = {0};
    int32_t neg_array[SIZE] = {0};

    if (!read_array(array, SIZE))
        return EXIT_FAILURE;
    
    const size_t n_pos = filter_array(array, SIZE,
        pos_array, SIZE, is_pos
    );
    const size_t n_neg = filter_array(array, SIZE,
        neg_array, SIZE, is_neg
    );

    print_array(pos_array, n_pos);
    print_array(neg_array, n_neg);
    
    return EXIT_SUCCESS;
}

bool read_array(int32_t *array,  size_t n)
{
    if (!array || !n)
        return false;

    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%" SCNd32, array + i) != 1)
            return false;
    }
    
    return true;
}

void print_array(const int32_t *array, size_t n)
{
    if (!array || !n)
    return;

    for (size_t i = 0; i < n; i++)
        printf("%" PRId32 " ", array[i]);
}

bool is_neg(int32_t n)
{
    return n < 0;
}

bool is_pos(int32_t n)
{
    return n > 0;
}

size_t filter_array(const int32_t *src_array, size_t src_array_size,
    int32_t *dest_array, size_t dest_array_size, bool (*predicate)(int32_t)
)
{
    if (src_array == dest_array || src_array_size < dest_array_size ||
        !src_array || !dest_array ||
        !src_array_size || !dest_array_size || !predicate
    )
    {
        return 0;
    }

    size_t j = 0;

    for (size_t i = 0; i < src_array_size; i++)
    {
        if (predicate(src_array[i]))
            dest_array[j++] = src_array[i];
    }

    return j;
}
