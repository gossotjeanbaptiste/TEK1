/*
** EPITECH PROJECT, 2024
** Project-my_ls
** File description:
** mini_printf_verif_case
*/

#include <stdarg.h>
#include "my.h"

void mini_printf_handle_string(const char *format, va_list args)
{
    char *str = va_arg(args, char *);

    my_putstr(str);
}

void mini_printf_handle_integer(const char *format, va_list args)
{
    int num = va_arg(args, int);

    my_put_nbr(num);
}

void mini_printf_handle_char(va_list args)
{
    char c = va_arg(args, int);

    my_putchar(c);
}

void mini_printf_handle_default(char c)
{
    my_putchar('%');
    my_putchar(c);
}

void mini_printf_verification_switch(const char *format, va_list args, int i)
{
    switch (format[i]) {
    case 's':
        mini_printf_handle_string(format, args);
        break;
    case 'd':
        mini_printf_handle_integer(format, args);
        break;
    case 'c':
        mini_printf_handle_char(args);
        break;
    case 'p':
        mini_printf_handle_pointer_p(args);
        break;
    case 'l':
        mini_printf_handle_long(args);
        break;
    default:
        mini_printf_handle_default(format[i]);
        break;
    }
}
