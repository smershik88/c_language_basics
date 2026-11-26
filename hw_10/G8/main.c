#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Числа в массив
В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
Вывести массив по возрастанию в файл output.txt.

Input format
Строка из английских букв, цифр и знаков препинания
Output format
Последовательность целых чисел отсортированная по возрастанию
Examples
Input in input.txt
data 48 call 9 read13 blank0a
Output in output.txt
0 9 13 48
*/

#define MAX_INPUT_STRING_LENGTH  1000U
#define INPUT_STRING_BUFFER_SIZE (MAX_INPUT_STRING_LENGTH + 2U)
#define MAX_COUNT_NUMBERS        (MAX_INPUT_STRING_LENGTH / 2U + MAX_INPUT_STRING_LENGTH % 2U)
#define DEC_RADIX                10
// #define MAX_OUTPUT_STRING_LENGTH  (2U * MAX_COUNT_DECIMAL_DIGITS + 1U)
// #define OUTPUT_STRING_BUFFER_SIZE (MAX_OUTPUT_STRING_LENGTH + 1U)

#define OPN_ERR_MSG  "File opening failed"
#define CLS_ERR_MSG  "File closing failed"
#define R_ERR_MSG    "File reading failed"
#define W_ERR_MSG    "File writing failed"
#define PROC_ERR_MSG "Processing error"
// #define INV_DATA_ERR_MSG "Invalid data"
// #define MEM_ALLOC_ERR_MSG "Memory allocating failed"

bool open_file(FILE **fp, const char *mode, const char *fname);
bool close_file(FILE **fp);
bool read_line_from_file(FILE *fp, char *string_buffer, size_t string_buffer_size,
                         size_t max_string_length);
bool write_longs_array_to_file(FILE *fp, const long *const array, size_t array_size,
                               const char *join_by);
bool get_numbers_from_string(const char *string, long *numbers, size_t *count_numbers,
                             size_t max_count_numbers);
int  compare_longs(const void *a, const void *b);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    const char *input_fname = "input.txt";
    // const char *input_fname = "C:\\Data\\Projects\\C\\c_language_basics\\hw_10\\G8\\input.txt";
    const char *input_mode   = "r";
    const char *output_fname = "output.txt";
    // const char *output_fname = "C:\\Data\\Projects\\C\\c_language_basics\\hw_10\\G8\\output.txt";
    const char *output_mode = "w";

    int result = EXIT_FAILURE;

    FILE *input_fp  = NULL;
    FILE *output_fp = NULL;

    char   input_string_buffer[INPUT_STRING_BUFFER_SIZE] = {0};
    long   numbers[MAX_COUNT_NUMBERS]                    = {0};
    size_t count_numbers                                 = 0;

    if (!open_file(&input_fp, input_mode, input_fname))
    {
        perror(OPN_ERR_MSG);
        goto cleanup;
    }

    if (!read_line_from_file(input_fp, input_string_buffer, sizeof(input_string_buffer),
                             MAX_INPUT_STRING_LENGTH))
    {
        (void)fputs(R_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    if (!get_numbers_from_string(input_string_buffer, numbers, &count_numbers,
                                 sizeof numbers / sizeof *numbers))
    {
        (void)fputs(PROC_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    qsort(numbers, count_numbers, sizeof *numbers, compare_longs);

    if (!open_file(&output_fp, output_mode, output_fname))
    {
        perror(OPN_ERR_MSG);
        goto cleanup;
    }

    if (!write_longs_array_to_file(output_fp, numbers, count_numbers, " "))
    {
        (void)fputs(W_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    result = EXIT_SUCCESS;

cleanup:
    if (!close_file(&output_fp))
    {
        perror(CLS_ERR_MSG);
        result = EXIT_FAILURE;
    }

    if (!close_file(&input_fp))
    {
        perror(CLS_ERR_MSG);
        result = EXIT_FAILURE;
    }

    return result;
}

bool open_file(FILE **fp, const char *mode, const char *fname)
{
    if (fp == NULL || *fp != NULL || fname == NULL || mode == NULL)
    {
        return false;
    }

    *fp = fopen(fname, mode);

    return *fp != NULL;
}

bool close_file(FILE **fp)
{
    if (fp == NULL)
    {
        return false;
    }

    if (*fp == NULL)
    {
        return true;
    }

    int close_result = fclose(*fp);

    *fp = NULL;

    return close_result != EOF;
}

bool read_line_from_file(FILE *fp, char *string_buffer, size_t string_buffer_size,
                         size_t max_string_length)
{
    if (fp == NULL || string_buffer == NULL || string_buffer_size < 2 ||
        string_buffer_size > (size_t)INT_MAX || max_string_length > string_buffer_size - 2)
    {
        return false;
    }

    if (fgets(string_buffer, (int)string_buffer_size, fp) == NULL)
    {
        return false;
    }

    char *end_line = strpbrk(string_buffer, "\r\n");

    size_t input_string_length;

    if (end_line != NULL)
    {
        *end_line           = '\0';
        input_string_length = (size_t)(end_line - string_buffer);
    }
    else
    {
        input_string_length = strlen(string_buffer);
    }

    if (ferror(fp) || input_string_length > max_string_length)
    {
        return false;
    }

    return true;
}

bool write_longs_array_to_file(FILE *fp, const long *const array, size_t array_size,
                               const char *join_by)
{
    if (fp == NULL || array == NULL)
    {
        return false;
    }

    if (join_by == NULL)
    {
        join_by = "";
    }

    int written = 0;

    for (size_t i = 0; i < array_size; ++i)
    {
        if (fputs(written == 0 ? "" : join_by, fp) == EOF)
        {
            return false;
        }
        if ((written = fprintf(fp, "%ld", array[i])) < 0)
        {
            return false;
        }
    }

    return true;
}

bool get_numbers_from_string(const char *string, long *numbers, size_t *count_numbers,
                             size_t max_count_numbers)
{
    if (string == NULL || numbers == NULL || count_numbers == NULL || max_count_numbers == 0)
    {
        return false;
    }

    if (strlen(string) == 0)
    {
        return false;
    }

    const char *digits       = "-0123456789";
    const char *start_number = string;

    while ((start_number = strpbrk(start_number, digits)) != NULL)
    {

        errno = 0;
        char *end;
        long  number = strtol(start_number, &end, DEC_RADIX);

        if (errno == ERANGE && (number == LONG_MAX || number == LONG_MIN))
        {
            return false;
        }

        start_number = end;

        if (++*count_numbers > max_count_numbers)
        {
            return false;
        }

        *numbers++ = number;
        // printf("%ld\n", number);
    }

    return true;
}

int compare_longs(const void *a, const void *b)
{
    if (a == NULL || b == NULL)
    {
        return 0;
    }

    const long *a_ptr = (const long *)a;
    const long *b_ptr = (const long *)b;

    return (*a_ptr - *b_ptr);
}
