#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
По одному разу
В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом. Найдите
только те символы слов, которые встречаются в обоих словах только один раз. Напечатайте их через
пробел в файл output.txt в лексикографическом порядке.

Input format
Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
Output format
Маленькие английские буквы через пробел.
Examples
Input in input.txt
hello world
Output in output.txt
o
Input in input.txt
aabcd bcef
Output in output.txt
b c
*/

#define MAX_WORD_LENGTH           100U
#define WORD_BUFFER_SIZE          (MAX_WORD_LENGTH + 2U)
#define MAX_OUTPUT_STRING_LENGTH  (MAX_WORD_LENGTH + MAX_WORD_LENGTH - 1U)
#define OUTPUT_STRING_BUFFER_SIZE (MAX_OUTPUT_STRING_LENGTH + 1U)

#define OPN_ERR_MSG      "File opening failed"
#define CLS_ERR_MSG      "File closing failed"
#define R_ERR_MSG        "File reading failed"
#define W_ERR_MSG        "File writing failed"
#define INV_DATA_ERR_MSG "Invalid data"
// #define MEM_ALLOC_ERR_MSG "Memory allocating failed"
#define PROC_ERR_MSG "Processing error"

bool open_file(FILE **fp, const char *mode, const char *fname);
bool close_file(FILE **fp);
bool read_two_words_from_file(FILE *fp, char *word1_buffer, size_t word1_buffer_size,
                              char *word2_buffer, size_t word2_buffer_size, size_t max_word_length);
bool write_string_to_file(FILE *fp, const char *string);
int  compare_chars(const void *a, const void *b);
bool vacuum_string(char *string_buffer, size_t string_buffer_size);
bool get_matching_chars(const char *word1_buffer, const char *word2_buffer,
                        char *matching_chars_buffer, size_t matching_chars_buffer_size);
bool matching_chars_to_string(const char *matching_chars_buffer, char *string_buffer,
                              size_t string_buffer_size);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    const char *input_fname = "C:\\Data\\Dev\\projects\\C\\c_language_basics\\hw_10\\G4\\input.txt";
    // const char *input_fname = "input.txt";
    const char *input_mode = "r";
    const char *output_fname =
        "C:\\Data\\Dev\\projects\\C\\c_language_basics\\hw_10\\G4\\output.txt";
    // const char *output_fname = "output.txt";
    const char *output_mode = "w";

    int result = EXIT_FAILURE;

    FILE *input_fp  = NULL;
    FILE *output_fp = NULL;

    char word1_buffer[WORD_BUFFER_SIZE]                  = {0};
    char word2_buffer[WORD_BUFFER_SIZE]                  = {0};
    char matching_chars_buffer[WORD_BUFFER_SIZE]         = {0};
    char output_string_buffer[OUTPUT_STRING_BUFFER_SIZE] = {0};

    if (!open_file(&input_fp, input_mode, input_fname))
    {
        perror(OPN_ERR_MSG);
        goto cleanup;
    }

    if (!read_two_words_from_file(input_fp, word1_buffer, sizeof(word1_buffer), word2_buffer,
                                  sizeof(word2_buffer), MAX_WORD_LENGTH))
    {
        (void)fputs(R_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    if (!vacuum_string(word1_buffer, sizeof(word1_buffer)))
    {
        (void)fputs(PROC_ERR_MSG "\n", stderr);
        goto cleanup;
    }
    if (!vacuum_string(word2_buffer, sizeof(word2_buffer)))
    {
        (void)fputs(PROC_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    if (!get_matching_chars(word1_buffer, word2_buffer, matching_chars_buffer,
                            sizeof(matching_chars_buffer)))
    {
        (void)fputs(PROC_ERR_MSG "\n", stderr);
        goto cleanup;
    }

    if (!matching_chars_to_string(matching_chars_buffer, output_string_buffer,
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

bool read_two_words_from_file(FILE *fp, char *word1_buffer, size_t word1_buffer_size,
                              char *word2_buffer, size_t word2_buffer_size, size_t max_word_length)
{
    if (fp == NULL || word1_buffer == NULL || word2_buffer == NULL || word1_buffer_size < 2 ||
        word2_buffer_size < 2 || max_word_length > word1_buffer_size - 2 ||
        max_word_length > word2_buffer_size - 2)
    {
        return false;
    }

    char format[]           = "%XXXs %XXXs";
    char max_word_len_str[] = "XXX";
    int  snprintf_result =
        snprintf(max_word_len_str, sizeof(max_word_len_str), "%zu", max_word_length + 1);

    if (snprintf_result < 0 || snprintf_result >= (int)sizeof(max_word_len_str))
    {
        return false;
    }

    snprintf_result =
        snprintf(format, sizeof(format), "%%%ss %%%ss", max_word_len_str, max_word_len_str);
    if (snprintf_result < 0 || snprintf_result >= (int)sizeof(format))
    {
        return false;
    }

    if (fscanf(fp, format, word1_buffer, word2_buffer) != 2)
    {
        return false;
    }

    if (strlen(word1_buffer) > max_word_length || strlen(word2_buffer) > max_word_length)
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

int compare_chars(const void *a, const void *b)
{

    const unsigned char char_a = *(const unsigned char *)a;
    const unsigned char char_b = *(const unsigned char *)b;

    return (int)char_a - (int)char_b;
}

bool vacuum_string(char *string_buffer, size_t string_buffer_size)
{
    if (string_buffer == NULL || string_buffer_size == 0)
    {
        return false;
    }

    size_t string_length = 0;

    while (string_length < string_buffer_size && string_buffer[string_length] != '\0')
    {
        ++string_length;
    }

    if (string_length == string_buffer_size)
    {
        return false;
    }

    qsort(string_buffer, string_length, sizeof(char), compare_chars);

    size_t i = 0;

    while (i < string_length)
    {
        if (string_buffer[i] == ' ')
        {
            ++i;
            continue;
        }

        size_t j = i + 1;

        while (j < string_length && string_buffer[j] == string_buffer[i])
        {
            ++j;
        }

        if (j - i > 1)
        {
            // Повтояющийся символ, удаляем его из строки, сдвигая оставшуюся часть строки вместе с
            // '\0' влево
            memmove(&string_buffer[i], &string_buffer[j], string_length - j + 1);
            // Обновляем длину строки после удаления повторяющихся символов
            string_length -= (j - i);
            // Не увеличиваем i, на текущую позицию переместилась новая группа символов, которую
            // нужно проверить на уникальность
            continue;
        }
        // Увеличиваем i только если текущий символ уникален и не был удален
        ++i;
    }

    return true;
}

bool get_matching_chars(const char *word1_buffer, const char *word2_buffer,
                        char *matching_chars_buffer, size_t matching_chars_buffer_size)
{
    if (word1_buffer == NULL || word2_buffer == NULL || matching_chars_buffer == NULL ||
        matching_chars_buffer_size == 0)
    {
        return false;
    }

    matching_chars_buffer[0] = '\0';

    size_t word1_length = strlen(word1_buffer);

    for (size_t i = 0; i < word1_length; ++i)
    {
        char current_char = word1_buffer[i];

        if (strchr(word2_buffer, current_char) != NULL)
        {
            size_t current_length = strlen(matching_chars_buffer);

            if (current_length >= matching_chars_buffer_size - 1)
            {
                return false;
            }

            matching_chars_buffer[current_length]     = current_char;
            matching_chars_buffer[current_length + 1] = '\0';
        }
    }

    return true;
}

bool matching_chars_to_string(const char *matching_chars_buffer, char *string_buffer,
                              size_t string_buffer_size)
{
    if (matching_chars_buffer == NULL || string_buffer == NULL || string_buffer_size == 0)
    {
        return false;
    }

    string_buffer[0] = '\0';

    size_t matching_chars_length = strlen(matching_chars_buffer);

    for (size_t i = 0; i < matching_chars_length; ++i)
    {
        size_t available_size = string_buffer_size - strlen(string_buffer);

        int snprintf_result =
            snprintf(string_buffer + strlen(string_buffer), available_size, "%s%c",
                     strlen(string_buffer) == 0 ? "" : " ", matching_chars_buffer[i]);

        if (snprintf_result < 0 || (size_t)snprintf_result >= available_size)
        {
            return false;
        }
    }

    return true;
}
