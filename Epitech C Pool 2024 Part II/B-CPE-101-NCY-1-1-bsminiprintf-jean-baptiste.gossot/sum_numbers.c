/*
** EPITECH PROJECT, 2024
** sum_number
** File description:
** sum the number into a variadric list
*/

#include "bsprintf.h"
#include <stdarg.h>

int sum_numbers(int n, ...)
{
    va_list list;
    int sum = 0;

    va_start(list, n);
    for (int i = 0; i < n; i++) {
        sum += va_arg(list, int);
    }
    va_end(list);
    return sum;
}
