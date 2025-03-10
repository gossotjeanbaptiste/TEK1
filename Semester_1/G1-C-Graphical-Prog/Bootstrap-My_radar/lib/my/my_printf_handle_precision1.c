/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
** File description:
** my_printf_handle_precision
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void handle_precision(const char *format, va_list args, int i)
{
    int precision = 0;

    if (format[i + 1] == '.') {
        i += 2;
        while (format[i] >= '0' && format[i] <= '9') {
            precision = precision * 10 + (format[i] - '0');
            i++;
        }
        i--;
    }
}

void handle_precision_switch_case(const char *format, va_list args, int i,
    int precision)
{
    switch (format[i]) {
        case 's':
            handle_string_precision(format, args, precision);
            break;
        case 'd':
            handle_integer_precision(format, args, precision);
            break;
        case 'x':
            handle_hex_precision(args, 0, precision);
            break;
        case 'X':
            handle_hex_precision(args, 1, precision);
            break;
        default:
            handle_precision2(format, args, i, precision);
            break;
    }
}

void handle_precision2(const char *format, va_list args, int i, int precision)
{
    switch (format[i]) {
    case 'h':
        my_put_short_int(va_arg(args, int));
        break;
    case 'l':
        my_put_long(va_arg(args, long));
        break;
    case 'L':
        my_put_long_double(va_arg(args, long double));
        break;
    case 'j':
        handle_intmax(args);
        break;
    case 't':
        handle_ptrdiff(args);
        break;
    default:
        handle_precision3(format, args, i, precision);
        break;
    }
}

void handle_precision3(const char *format, va_list args, int i, int precision)
{
    switch (format[i]) {
    case 'q':
        my_put_long_long(va_arg(args, long long));
        break;
    case 'l':
        switch (format[i + 1]) {
        case 'l':
            my_put_long_long(va_arg(args, long long));
            break;
        default:
            break;
        }
        break;
    default:
        my_putchar(format[i]);
        break;
    }
}
