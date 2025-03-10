/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** mini_printf_essai
*/

#include <stdarg.h>
#include "my.h"

/**
 * @brief Verifies and processes a switch case based on the given format string
 *
 * This function takes a format string, a variable argument list, and an index,
 * and performs verification and processing of a switch case.
 *
 * @param format The format string to be processed.
 * @param args The variable argument list containing the arguments
 * to be processed.
 * @param i The index indicating the current position in the format string.
 */
void verification_switch1(const char *format, va_list args, int i)
{
    switch (format[i]) {
    case 's':
        handle_string(format, args);
        break;
    case 'd':
        handle_integer(format, args);
        break;
    case 'c':
        handle_char(args);
        break;
    case 'x':
        handle_hex(args, 0);
        break;
    case 'X':
        handle_hex(args, 1);
        break;
    default:
        verification_switch2(format, args, i);
        break;
    }
}

void verification_switch2(const char *format, va_list args, int i)
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
        verification_switch3(format, args, i);
        break;
    }
}

void verification_switch3(const char *format, va_list args, int i)
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
            my_put_long(va_arg(args, long));
            break;
        }
        break;
    default:
        verification_switch4(format, args, i);
        break;
    }
}

void verification_switch4(const char *format, va_list args, int i)
{
    switch (format[i]) {
        case 'u':
            handle_unsigned_u(args);
            break;
        case 'f':
        case 'F':
            handle_float_f(args);
            break;
        case 'p':
            handle_pointer_p(args);
            break;
        case '.':
            handle_precision(format, args, i + 1);
            break;
        default:
            verification_switch5(format, args, i);
            break;
    }
}

void verification_switch5(const char *format, va_list args, int i)
{
    switch (format[i]) {
        case 'e':
        case 'E':
            handle_float_e(args, format[i]);
            break;
        case '+':
            if (va_arg(args, int) >= 0)
                my_putchar('+');
            my_put_nbr(va_arg(args, int));
            break;
        default:
            my_putchar(format[i]);
            break;
    }
}
