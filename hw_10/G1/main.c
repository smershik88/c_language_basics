#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Три раза
В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать
количество символов в ней.

Input format
Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы
строк.
Output format
Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.
Examples
Input in input.txt
aab
Output in output.txt
aab, aab, aab 3
*/

#define STRING_BUFFER_SIZE 101

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    const char *input_fname  = "input.txt";
    const char *input_mode   = "r";
    const char *output_fname = "output.txt";
    const char *output_mode  = "w";

    const char *opening_failed_msg       = "File opening failed";
    const char *closing_failed_msg       = "File closing failed";
    const char *reading_failed_msg       = "File reading failed";
    const char *writing_failed_msg       = "File writing failed";
    const char *invalid_input_length_msg = "Invalid input length";

    int result = EXIT_FAILURE;

    FILE *input_fp  = NULL;
    FILE *output_fp = NULL;

    char string_buffer[STRING_BUFFER_SIZE] = {0};

    input_fp = fopen(input_fname, input_mode);

    if (input_fp == NULL)
    {
        perror(opening_failed_msg);
        goto cleanup;
    }

    if (fgets(string_buffer, sizeof(string_buffer), input_fp) == NULL)
    {
        (void)fputs(reading_failed_msg, stderr);
        goto cleanup;
    }

    {
        const size_t pure_string_len = strcspn(string_buffer, "\r\n");

        if (pure_string_len >= sizeof(string_buffer))
        {
            (void)fputs(invalid_input_length_msg, stderr);
            goto cleanup;
        }

        string_buffer[pure_string_len] = '\0';

        output_fp = fopen(output_fname, output_mode);

        if (output_fp == NULL)
        {
            perror(opening_failed_msg);
            goto cleanup;
        }

        if (fprintf(output_fp, "%s, %s, %s %zu", string_buffer, string_buffer, string_buffer,
                    pure_string_len) < 0)
        {
            (void)fputs(writing_failed_msg, stderr);
            goto cleanup;
        }
    }

    result = EXIT_SUCCESS;

cleanup:
    if (output_fp != NULL)
    {
        if (fclose(output_fp) == EOF)
        {
            perror(closing_failed_msg);
            result = EXIT_FAILURE;
        }
    }

    if (input_fp != NULL)
    {
        if (fclose(input_fp) == EOF)
        {
            perror(closing_failed_msg);
            result = EXIT_FAILURE;
        }
    }

    return result;
}
