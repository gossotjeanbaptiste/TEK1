/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** display each char of a string
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int my_putnstr(char const *str, int precision)
{
    int i = 0;

    while (str[i] != '\0' && i < precision){
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
