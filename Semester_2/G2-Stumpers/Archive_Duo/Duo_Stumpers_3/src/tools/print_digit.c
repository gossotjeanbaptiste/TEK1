/*
** EPITECH PROJECT, 2025
** tools
** File description:
** print_digit
*/

#include <stdio.h>
#include "../../include/tools.h"

void print_digit(const char c, char *str)
{
    if (c && c != '0')
        replace_char(c, str);
    printf("%s", str);
}
