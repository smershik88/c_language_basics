#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Заменить a на b
В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а"
на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.

Input format
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Output format
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Examples
Input in input.txt
aabbccddABCD
Output in output.txt
bbaaccddBACD
*/

#define MAX_INPUT_STRING_LENGTH   1000U
#define INPUT_STRING_BUFFER_SIZE  (MAX_INPUT_STRING_LENGTH + 2U)
#define MAX_OUTPUT_STRING_LENGTH  (MAX_INPUT_STRING_LENGTH)
#define OUTPUT_STRING_BUFFER_SIZE (MAX_OUTPUT_STRING_LENGTH + 1U)

#define OPN_ERR_MSG "File opening failed"
#define CLS_ERR_MSG "File closing failed"
#define R_ERR_MSG   "File reading failed"
#define W_ERR_MSG   "File writing failed"
// #define INV_DATA_ERR_MSG "Invalid data"
// #define MEM_ALLOC_ERR_MSG "Memory allocating failed"
#define PROC_ERR_MSG "Processing error"

typedef struct replace_char_pair
{
    char from;
    char to;
} replace_char_pair_t;

bool open_file(FILE **fp, const char *mode, const char *fname);
bool close_file(FILE **fp);
bool read_line_from_file(FILE *fp, char *string_buffer, size_t string_buffer_size,
                         size_t max_string_length);
bool write_string_to_file(FILE *fp, const char *string);
bool replace_chars_in_string(const char *src_string, char *dest_string_buffer,
                             size_t                     dest_string_buffer_size,
                             const replace_char_pair_t *replace_pairs, size_t replace_pairs_count,
                             size_t *replacements_count);
int  main(int argc, char *argv[])
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

    char input_string_buffer[INPUT_STRING_BUFFER_SIZE]   = {0};
    char output_string_buffer[OUTPUT_STRING_BUFFER_SIZE] = {0};

    const replace_char_pair_t replace_pairs[] = {
        {'a', 'b'},
        {'b', 'a'},
        {'A', 'B'},
        {'B', 'A'},
    };

    const size_t replace_pairs_count = sizeof(replace_pairs) / sizeof(replace_pairs[0]);

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

    if (!replace_chars_in_string(input_string_buffer, output_string_buffer,
                                 sizeof(output_string_buffer), replace_pairs, replace_pairs_count,
                                 NULL))
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

bool replace_chars_in_string(const char *src_string, char *dest_string_buffer,
                             size_t                     dest_string_buffer_size,
                             const replace_char_pair_t *replace_pairs, size_t replace_pairs_count,
                             size_t *replacements_count)
{
    if (replacements_count != NULL)
    {
        *replacements_count = 0;
    }

    if (src_string == NULL || dest_string_buffer == NULL || dest_string_buffer_size == 0 ||
        (replace_pairs_count > 0 && replace_pairs == NULL))
    {
        return false;
    }

    size_t string_length = strlen(src_string);

    if (string_length >= dest_string_buffer_size)
    {
        return false;
    }

    memmove(dest_string_buffer, src_string, string_length + 1);

    for (size_t i = 0; i < string_length; ++i)
    {
        for (size_t j = 0; j < replace_pairs_count; ++j)
        {
            if (dest_string_buffer[i] == replace_pairs[j].from)
            {
                dest_string_buffer[i] = replace_pairs[j].to;
                if (replacements_count != NULL)
                {
                    ++*replacements_count;
                }
                break;
            }
        }
    }

    return true;
}
