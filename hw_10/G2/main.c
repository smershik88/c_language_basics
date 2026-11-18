#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Строка и цифры
Считать число N из файла input.txt. Сформировать строку из N символов. N четное число, не
превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания, кроме 0,
на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. Результат
записать в файл output.txt

Input format
Четное N ≤ 26
Output format
Строка из английских букв и цифр
Examples
Input in input.txt
10
Output in output.txt
A2B4C6D8E2
Input in input.txt
16
Output in output.txt
A2B4C6D8E2F4G6H8
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
