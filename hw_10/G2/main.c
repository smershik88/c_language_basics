#include <limits.h>
#include <stdbool.h>
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

#define INPUT_STRING_BUFFER_SIZE 12
#define MAX_NUMBER               26
#define DEC_RADIX                10
#define MAX_EVEN_DIGIT           8

#define OPN_ERR_MSG       "File opening failed"
#define CLS_ERR_MSG       "File closing failed"
#define R_ERR_MSG         "File reading failed"
#define W_ERR_MSG         "File writing failed"
#define INV_DATA_ERR_MSG  "Invalid data"
#define MEM_ALLOC_ERR_MSG "Memory allocating failed"
#define PROC_ERR_MSG      "Processing error"

bool   open_file(FILE **fp, const char *mode, const char *fname);
bool   close_file(FILE **fp);
bool   read_long_from_file(FILE *fp, char *buffer, size_t buffer_size, long *n);
bool   long_to_digits_and_letters(unsigned long n, char *string, size_t string_len);
size_t max_long_str_len(void);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    // const char *input_fname  = "C:\\Data\\Projects\\C\\c_language_basics\\hw_10\\G2\\input.txt";
    const char *input_fname = "input.txt";
    const char *input_mode  = "r";
    // const char *output_fname = "C:\\Data\\Projects\\C\\c_language_basics\\hw_10\\G2\\output.txt";
    const char *output_fname = "output.txt";
    const char *output_mode  = "w";

    int result = EXIT_FAILURE;

    FILE *input_fp  = NULL;
    FILE *output_fp = NULL;

    char   input_string_buffer[INPUT_STRING_BUFFER_SIZE] = {0};
    long   n                                             = 0;
    char  *result_string_buffer                          = NULL;
    size_t result_string_buffer_size                     = 0;

    if (!open_file(&input_fp, input_mode, input_fname))
    {
        perror(OPN_ERR_MSG);
        goto cleanup;
    }

    if (!read_long_from_file(input_fp, input_string_buffer, sizeof(input_string_buffer), &n))
    {
        (void)fputs(R_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    if (n > MAX_NUMBER || n % 2 != 0)
    {
        (void)fputs(INV_DATA_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    if (n < 0)
    {
        n = -n;
    }

    if (!open_file(&output_fp, output_mode, output_fname))
    {
        perror(OPN_ERR_MSG);
        goto cleanup;
    }

    result_string_buffer_size = (unsigned long)n * 2 + 1;
    result_string_buffer      = calloc(result_string_buffer_size, sizeof(char));
    if (result_string_buffer == NULL)
    {
        (void)fputs(MEM_ALLOC_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    if (!long_to_digits_and_letters((unsigned long)n, result_string_buffer,
                                    result_string_buffer_size - 1))
    {
        (void)fputs(PROC_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    printf("%s", result_string_buffer);

    if (fprintf(output_fp, "%s", result_string_buffer) < 0)
    {
        (void)fputs(W_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    result = EXIT_SUCCESS;

cleanup:
    free(result_string_buffer);
    result_string_buffer = NULL;

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
    bool result = false;

    if (*fp != NULL || fname == NULL || mode == NULL)
    {
        return result;
    }

    *fp = fopen(fname, mode);

    if (*fp == NULL)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
}

bool close_file(FILE **fp)
{
    bool result = false;

    if (*fp == NULL)
    {
        return result;
    }

    if (fclose(*fp) == 0)
    {
        *fp    = NULL;
        result = true;
    }

    return result;
}

bool read_long_from_file(FILE *fp, char *buffer, size_t buffer_size, long *n)
{
    bool result = false;

    const size_t buffer_size_min = max_long_str_len();
    if (fp == NULL || buffer == NULL || n == NULL || buffer_size < buffer_size_min)
    {
        return result;
    }

    if (buffer_size > INT_MAX)
    {
        return result;
    }

    if (fgets(buffer, (int)buffer_size, fp) == NULL)
    {
        return result;
    }

    const size_t pure_string_len = strcspn(buffer, "\r\n");
    if (pure_string_len >= buffer_size)
    {
        return result;
    }
    buffer[pure_string_len] = '\0';

    char *end_ptr = NULL;
    long  num     = strtol(buffer, &end_ptr, DEC_RADIX);
    if (num == 0 && end_ptr == buffer + pure_string_len)
    {
        return result;
    }

    *n     = num;
    result = true;
    return result;
}

bool long_to_digits_and_letters(unsigned long n, char *string, size_t string_len)
{
    bool               result = false;
    const unsigned int max_n  = 26;

    if (string == NULL || n > max_n || string_len < n * 2)
    {
        return result;
    }

    char         letter = 'A';
    unsigned int number = 0;

    for (size_t i = 0; i < n; i++)
    {
        if ((i + 1) & 1U)
        {
            string[i] = letter++;
            // printf("%c ", letter++);
        }
        else
        {
            number    = number % MAX_EVEN_DIGIT + 2;
            string[i] = (char)(number + '0');
            // printf("%d ", number);
        }
    }

    result = true;
    return result;
}

size_t max_long_str_len(void)
{
    int n = snprintf(NULL, 0, "%ld", LONG_MIN);
    return (size_t)n + 1;
}
