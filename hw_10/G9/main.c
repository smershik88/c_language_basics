#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Удалить повторяющиеся символы
В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.

Input format
Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более
1000 сивмолов.
Output format Строка из меленьких и больших английских букв.
Examples
Input in input.txt
abc cde def
Output in output.txt
abcdef
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
bool write_longs_array_to_file(FILE *fp, const long *array, size_t array_size, const char *join_by);
bool get_numbers_from_string(const char *string, long *numbers, size_t *count_numbers,
                             size_t max_count_numbers);
int  compare_longs(const void *a, const void *b);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    const char *input_fname  = "input.txt";
    const char *input_mode   = "r";
    const char *output_fname = "output.txt";
    const char *output_mode  = "w";

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

bool write_longs_array_to_file(FILE *fp, const long *array, size_t array_size, const char *join_by)
{
    if (fp == NULL || (array_size > 0 && array == NULL))
    {
        return false;
    }

    if (join_by == NULL)
    {
        join_by = "";
    }

    for (size_t i = 0; i < array_size; ++i)
    {
        if (i > 0 && fputs(join_by, fp) == EOF)
        {
            return false;
        }

        if (fprintf(fp, "%ld", array[i]) < 0)
        {
            return false;
        }
    }

    return true;
}

bool get_numbers_from_string(const char *string, long *numbers, size_t *count_numbers,
                             size_t max_count_numbers)
{
    if (string == NULL || numbers == NULL || count_numbers == NULL)
    {
        return false;
    }

    const char *number_start_chars = "-0123456789";
    const char *start_number       = string;
    *count_numbers                 = 0;

    while ((start_number = strpbrk(start_number, number_start_chars)) != NULL)
    {

        errno        = 0;
        char *end    = NULL;
        long  number = strtol(start_number, &end, DEC_RADIX);

        if (end == start_number)
        {
            ++start_number;
            continue;
        }

        if (errno == ERANGE)
        {
            return false;
        }

        if (*count_numbers >= max_count_numbers)
        {
            return false;
        }

        numbers[*count_numbers] = number;
        ++*count_numbers;

        start_number = end;
    }

    return true;
}

int compare_longs(const void *a, const void *b)
{
    const long a_value = *(const long *)a;
    const long b_value = *(const long *)b;

    return (a_value > b_value) - (a_value < b_value);
}
