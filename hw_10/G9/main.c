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
#define CHAR_VALUES_COUNT        ((size_t)UCHAR_MAX + 1U)

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
bool write_string_to_file(FILE *fp, const char *string);
void remove_spaces_and_duplicates(char *string);

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

    char input_string_buffer[INPUT_STRING_BUFFER_SIZE] = {0};

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

    remove_spaces_and_duplicates(input_string_buffer);

    if (!open_file(&output_fp, output_mode, output_fname))
    {
        perror(OPN_ERR_MSG);
        goto cleanup;
    }

    if (!write_string_to_file(output_fp, input_string_buffer))
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

void remove_spaces_and_duplicates(char *string)
{
    if (string == NULL)
    {
        return;
    }

    bool chars_seen[CHAR_VALUES_COUNT] = {false};

    size_t read_index  = 0;
    size_t write_index = 0;

    while (string[read_index] != '\0')
    {
        unsigned char current_char = (unsigned char)string[read_index++];

        // Пропускаем пробелы.
        if (current_char == ' ')
        {
            continue;
        }

        // Пропускаем уже встречавшиеся символы.
        if (chars_seen[current_char])
        {
            continue;
        }

        chars_seen[current_char] = true;

        // Сохраняем первое вхождение символа.
        string[write_index++] = (char)current_char;
    }

    // Завершаем результирующую строку.
    string[write_index] = '\0';
}
