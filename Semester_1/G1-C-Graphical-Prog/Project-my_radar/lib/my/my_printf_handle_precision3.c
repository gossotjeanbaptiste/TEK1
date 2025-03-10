/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
** File description:
** my_printf_handle_precision3
*/

#include <stdarg.h>
#include "my.h"

int my_putn_hex(unsigned int nb, int is_upper, int precision)
{
    int res = 0;
    int remainder = 0;
    char digit;

    if (nb >= 16) {
        res += my_putn_hex(nb / 16, is_upper, precision - 1);
        remainder = nb % 16;
        if (remainder > 9) {
            digit = remainder + (is_upper ? 'A' - 10 : 'a' - 10);
        } else {
            digit = remainder + '0';
        }
        my_putchar(digit);
        res += 1;
    } else {
        annexe_my_putn_hex(remainder, is_upper, nb, res);
    }
}

void annexe_my_putn_hex(int remainder, int is_upper, int nb, int res)
{
    char digit;

    remainder = nb % 16;
    if (remainder > 9) {
        digit = remainder + (is_upper ? 'A' - 10 : 'a' - 10);
    } else {
        digit = remainder + '0';
    }
    my_putchar(digit);
    res += 1;
}

void handle_string_precision(const char *format, va_list args, int precision)
{
    char *str = va_arg(args, char *);

    if (precision == 0) {
        my_putstr(str);
    } else {
        my_putnstr(str, precision);
    }
}

void handle_integer_precision(const char *format, va_list args, int precision)
{
    int nb = va_arg(args, int);

    if (precision == 0) {
        my_put_nbr(nb);
    } else {
        my_putn_nbr(nb, precision);
    }
}

void handle_hex_precision(va_list args, int is_upper, int precision)
{
    unsigned int nb = va_arg(args, unsigned int);

    if (precision == 0)
        my_put_hex(nb, is_upper, precision);
    else
        my_putn_hex(nb, is_upper, precision);
}
