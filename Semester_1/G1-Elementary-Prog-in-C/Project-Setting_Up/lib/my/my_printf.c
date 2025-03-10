/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** mini_printf
*/

#include <stdarg.h>
#include "my.h"

int my_printf(const char *format, ...)
{
    int format_len = my_strlen(format);
    va_list list;

    va_start(list, format);
    if (error_handler(format, format_len) == 84) {
        va_end(list);
        return 84;
    }
    my_vprintf(format, list);
    va_end(list);
    return 0;
}
