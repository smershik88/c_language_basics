#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Последний номер символа
В файле input.txt дана строка из не более 1000 символов. Показать номера символов, совпадающих с
последним символом строки. Результат записать в файл output.txt

Input format
Строка из не более 1000 символов
Output format
Целые числа через пробел - номера символа, который совпадает с последним символом строки.
Examples
Input in input.txt
aabbcdb
Output in output.txt
2 3
*/

#define MAX_INPUT_STRING_LENGTH   1000U
#define INPUT_STRING_BUFFER_SIZE  (MAX_INPUT_STRING_LENGTH + 2U)
#define OUTPUT_STRING_BUFFER_SIZE (MAX_INPUT_STRING_LENGTH * 4U + 1U)

#define OPN_ERR_MSG      "File opening failed"
#define CLS_ERR_MSG      "File closing failed"
#define R_ERR_MSG        "File reading failed"
#define W_ERR_MSG        "File writing failed"
#define INV_DATA_ERR_MSG "Invalid data"
// #define MEM_ALLOC_ERR_MSG "Memory allocating failed"
#define PROC_ERR_MSG "Processing error"

bool open_file(FILE **fp, const char *mode, const char *fname);
bool close_file(FILE **fp);
bool read_line_from_file(FILE *fp, char *string_buffer, size_t string_buffer_size,
                         size_t max_string_length);
bool get_letter_indexes_str(const char *string_buffer, char letter, char *result_string_buffer,
                            size_t result_string_buffer_size);
bool write_string_to_file(FILE *fp, const char *string);

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

    char   string_buffer[INPUT_STRING_BUFFER_SIZE]         = {0};
    char   output_string_buffer[OUTPUT_STRING_BUFFER_SIZE] = {0};
    size_t input_string_length                             = 0;
    char   last_letter                                     = '\0';

    if (!open_file(&input_fp, input_mode, input_fname))
    {
        perror(OPN_ERR_MSG);
        goto cleanup;
    }

    if (!read_line_from_file(input_fp, string_buffer, sizeof(string_buffer),
                             MAX_INPUT_STRING_LENGTH))
    {
        (void)fputs(R_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    input_string_length = strlen(string_buffer);

    if (input_string_length == 0)
    {
        (void)fputs(INV_DATA_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    last_letter = string_buffer[input_string_length - 1];

    if (!get_letter_indexes_str(string_buffer, last_letter, output_string_buffer,
                                sizeof(output_string_buffer)))
    {
        (void)fputs(PROC_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    if (!open_file(&output_fp, output_mode, output_fname))
    {
        perror(OPN_ERR_MSG);
        goto cleanup;
    }

    if (!write_string_to_file(output_fp, output_string_buffer))
    {
        perror(W_ERR_MSG);
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

bool get_letter_indexes_str(const char *string_buffer, char letter, char *result_string_buffer,
                            size_t result_string_buffer_size)
{
    if (string_buffer == NULL || result_string_buffer == NULL || result_string_buffer_size == 0)
    {
        return false;
    }

    result_string_buffer[0] = '\0';

    size_t input_string_length = strlen(string_buffer);

    if (input_string_length == 0)
    {
        return false;
    }

    size_t result_string_length = 0;

    for (size_t i = 0; i < input_string_length - 1; ++i)
    {
        if (string_buffer[i] == letter)
        {
            size_t available_size = result_string_buffer_size - result_string_length;

            int snprintf_result =
                snprintf(result_string_buffer + result_string_length, available_size, "%s%zu",
                         result_string_length == 0 ? "" : " ", i);

            if (snprintf_result < 0 || (size_t)snprintf_result >= available_size)
            {
                return false;
            }

            result_string_length += (size_t)snprintf_result;
        }
    }

    return true;
}

bool write_string_to_file(FILE *fp, const char *string)
{
    if (fp == NULL || string == NULL)
    {
        return false;
    }

    if (fputs(string, fp) == EOF)
    {
        return false;
    }

    return true;
}
