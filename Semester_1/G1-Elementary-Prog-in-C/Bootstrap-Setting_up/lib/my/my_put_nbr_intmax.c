/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
** File description:
** my_put_intmax
*/

#include <inttypes.h>
#include "my.h"
#include <stdarg.h>

int handle_intmax(va_list args)
{
    intmax_t num = va_arg(args, intmax_t);

    return my_putnbr_intmax(num);
}

int my_putnbr_intmax(intmax_t num)
{
    char buffer[21];
    int i = 20;
    int is_negative = (num < 0);

    buffer[i] = '\0';
    i--;
    if (is_negative) {
        num = -num;
    }
    if (num == 0) {
        buffer[i] = '0';
        i--;
    } else {
        i = annexe_my_putnbr_intmax(num, buffer, i);
    }
    if (is_negative) {
        buffer[i] = '-';
        i--;
    }
    write(1, &buffer[i + 1], 20 - i - 1);
}

int annexe_my_putnbr_intmax(intmax_t num, char *buffer, int i)
{
    while (num > 0) {
        buffer[i] = '0' + (num % 10);
        num /= 10;
        i--;
    }
    return i;
}
