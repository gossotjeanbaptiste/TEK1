/*
** EPITECH PROJECT, 2024
** Epi-Template-C
** File description:
** mini_vprintf
*/
#include "my.h"
#include <stdarg.h>

void mini_vprintf(const char *format, va_list args)
{
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            mini_printf_verification_switch(format, args, i);
        } else {
            my_putchar(format[i]);
        }
    }
}
