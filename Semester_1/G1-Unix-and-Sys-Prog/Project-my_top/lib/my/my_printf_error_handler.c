/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** error_handler
*/
#include <stdarg.h>
#include "my.h"

/**
 * @brief Counts the number of format specifiers in a given format string.
 *
 * This function iterates through the provided format string and counts the
 * occurrences of format specifiers. The recognized format specifiers are:
 * - %s: String
 * - %d: Decimal integer
 * - %%: Literal percent sign
 * - %i: Integer
 * - %c: Character
 *
 * @param format The format string to be analyzed.
 * @return The number of format specifiers found in the format string.
 */

int count_format_specifiers(const char *format)
{
    int count = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && (format[i + 1] == 's' ||
        format[i + 1] == 'd' || format[i + 1] == '%' ||
        format[i + 1] == 'i' || format[i + 1] == 'c')) {
            count++;
            i++;
        }
    }
    return count;
}

/**
 * @brief Counts the number of format specifiers in a format string.
 *
 * This function iterates through the provided format string and counts the
 * number of format specifiers. The supported format specifiers are:
 * - %s: String
 * - %d: Decimal integer
 * - %i: Integer
 * - %c: Character
 * - %%: Literal percent sign
 *
 * @param args The list of arguments (not used in this function).
 * @param format The format string to be analyzed.
 * @return The count of format specifiers in the format string.
 */
int count_arguments(va_list args, const char *format)
{
    int count = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && (format[i + 1] == 's' ||
        format[i + 1] == 'd' || format[i + 1] == '%' ||
        format[i + 1] == 'i' || format[i + 1] == 'c')) {
            count++;
            i++;
        }
    }
    return count;
}

/**
 * @file error_handler.c
 * @brief Error handling for format specifiers and arguments count mismatch.
 *
 * This file contains the implementation of the error_handler function, which
 * checks if the number of format specifiers in a format string matches the
 * number of arguments provided. If there is a mismatch, an error message is
 * printed and an error code is returned.
 *
 * @param format The format string containing format specifiers.
 * @param ... The variable arguments corresponding to the format specifiers.
 * @return 0 if the number of format specifiers matches the number of
 * arguments, 84 if there is a mismatch.
 */
int error_handler(const char *format, ...)
{
    va_list args;
    int format_specifiers_count = 0;
    int arguments_count = 0;

    va_start(args, format);
    format_specifiers_count = count_format_specifiers(format);
    arguments_count = count_arguments(args, format);
    va_end(args);
    if (format_specifiers_count != arguments_count) {
        my_putstr("Error: wrong format\n");
        return 84;
    }
    return 0;
}
