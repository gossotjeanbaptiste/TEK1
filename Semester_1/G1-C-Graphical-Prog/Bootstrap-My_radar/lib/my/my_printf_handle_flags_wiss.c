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

void handle_ptrdiff(va_list args)
{
    long max = 9223372036854775807;
    long min = -9223372036854775807;
    ptrdiff_t value = va_arg(args, ptrdiff_t);

    if (value > min && value <= max) {
        my_put_long(value);
    } else {
        my_put_long_long(value);
    }
}

void handle_hex(va_list args, int uppercase)
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[9];
    int i = 7;
    char letter_offset = uppercase ? 'A' : 'a';
    int digit = 0;

    buffer[8] = '\0';
    if (num == 0) {
        buffer[i] = '0';
        i--;
    }
    while (num > 0) {
        digit = num % 16;
        buffer[i] = (digit < 10) ? ('0' + digit) :
        (letter_offset + (digit - 10));
        i--;
        num /= 16;
    }
    my_putstr(&buffer[i + 1]);
}

int handle_unsigned_u(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char str[12];
    int printed_chars = 0;
    int len = my_convert_num_to_str(num, str);

    if (len < 0) {
        return -1;
    }
    printed_chars = my_putstr(str);
    return printed_chars;
}

int handle_float_f(va_list args)
{
    double num = va_arg(args, double);
    char int_part_str[20];
    char frac_part_str[7];
    int printed_chars = 0;
    int int_part = (int)num;
    int frac_part = (int)((num - int_part) * 1000000);
    int int_len = 0;

    if (num < 0) {
        my_putchar('-');
        printed_chars++;
        int_part = -int_part;
        frac_part = -frac_part;
    }
    int_len = my_convert_num_to_str(int_part, int_part_str);
    if (int_len < 0)
        return -1;
    printed_chars += my_putstr(int_part_str);
    printed_chars += handle_float_f_fraction(frac_part, frac_part_str);
    return printed_chars;
}

int handle_float_f_fraction(int frac_part, char *frac_part_str)
{
    int printed_chars = 0;
    int frac_len = 0;
    int i;

    my_putchar('.');
    printed_chars++;
    frac_len = my_convert_num_to_str(frac_part, frac_part_str);
    if (frac_len < 0)
        return -1;
    for (i = frac_len; i < 6; i++) {
        my_putchar('0');
        printed_chars++;
    }
    printed_chars += my_putstr(frac_part_str);
    return printed_chars;
}
