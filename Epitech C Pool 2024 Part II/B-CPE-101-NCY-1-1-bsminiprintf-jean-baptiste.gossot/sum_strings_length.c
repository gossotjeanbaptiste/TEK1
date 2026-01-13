/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-bsminiprintf-jean-baptiste.gossot
** File description:
** sum_strings_length
*/
#include "bsprintf.h"
#include <stdarg.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int sum_strings_length(int n, ...)
{
    va_list list;
    int total_len = 0;

    va_start(list, n);
    for (int i = 0; i < n; i++) {
        total_len += my_strlen(va_arg(list, char *));
    }
    return total_len;
}
