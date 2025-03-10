/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** mini_printf_essai
*/

#include <stdarg.h>
#include "my.h"


void handle_string(const char *format, va_list args)
{
    char *str = va_arg(args, char *);

    my_putstr(str);
}

void handle_integer(const char *format, va_list args)
{
    int num = va_arg(args, int);

    my_put_nbr(num);
}

void handle_char(va_list args)
{
    char c = va_arg(args, int);

    my_putchar(c);
}

void handle_default(char c)
{
    my_putchar('%');
    my_putchar(c);
}

void verification_switch(const char *format, va_list args, int i)
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
    default:
        handle_default(format[i]);
        break;
    }
}
