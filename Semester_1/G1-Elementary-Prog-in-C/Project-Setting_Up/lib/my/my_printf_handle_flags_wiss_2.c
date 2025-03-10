/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** mini_printf
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

int handle_pointer_p(va_list args)
{
    void *ptr = va_arg(args, void *);
    unsigned long address = (unsigned long)ptr;
    int printed_chars = 0;

    if (ptr == NULL) {
        printed_chars += my_putstr("(nil)");
        return printed_chars;
    }
    printed_chars += my_putstr("0x");
    printed_chars += my_put_hex((unsigned int)address, 0, 0);
    return printed_chars;
}

void handle_float_e(va_list args, char specifier)
{
    double num = va_arg(args, double);
    int exponent = 0;
    char sign = (num < 0) ? '-' : '+';
    char e_char;

    if (num < 0) {
        num = -num;
    }
    if (num != 0.0) {
        while (num >= 10.0) {
            num /= 10.0;
            exponent++;
        }
        while (num < 1.0) {
            num *= 10.0;
            exponent--;
        }
    }
    e_char = (specifier == 'e') ? 'e' : 'E';
    handle_float_e_second(sign, num, exponent, e_char);
}

int handle_float_e_second(char sign, double num, int exponent, char e_char)
{
    my_putchar(sign);
    if (num == 0.0) {
        my_putstr("0.000000");
    } else {
        my_put_float(num, 6);
    }
    my_putchar(e_char);
    if (exponent >= 0) {
        my_putchar('+');
    } else {
        my_putchar('-');
        exponent = -exponent;
    }
    if (exponent < 10)
        my_putchar('0');
    my_put_nbr(exponent);
}
