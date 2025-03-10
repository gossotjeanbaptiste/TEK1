/*
** EPITECH PROJECT, 2024
** my_showstr
** File description:
** print and return 0 to a string
*/
#include "my.h"

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_isprint((unsigned char)str[i])) {
            my_putchar(str[i]);
        } else {
            my_putstr("\\");
            my_puthex2((unsigned char)str[i]);
        }
        i++;
    }
    return 0;
}
