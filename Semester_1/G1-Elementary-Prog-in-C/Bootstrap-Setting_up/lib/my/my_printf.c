/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** mini_printf
*/

#include <stdarg.h>
#include "my.h"

void mini_vprintf(const char *format, va_list args)
{
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            verification_switch1(format, args, i);
        } else {
            my_putchar(format[i]);
        }
    }
}

int my_printf(const char *format, ...)
{
    int format_len = my_strlen(format);
    va_list list;

    va_start(list, format);
    if (error_handler(format, format_len) == 84) {
        va_end(list);
        return 84;
    }
    mini_vprintf(format, list);
    va_end(list);
    return 0;
}
