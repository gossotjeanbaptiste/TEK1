/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** error_handler
*/
#include <stdarg.h>
#include "my.h"

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
