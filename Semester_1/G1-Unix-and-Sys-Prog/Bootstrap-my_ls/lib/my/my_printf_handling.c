/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** mini_printf_essai
*/

// function used to handle basic types or arguments

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

void handle_percent(va_list args)
{
    char c = va_arg(args, int);

    my_putchar('%');
    my_putchar(c);
}
