/*
** EPITECH PROJECT, 2025
** clean_string (solo stumpers 1)
** File description:
** my_putstr
*/
#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_putstr(char *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return len;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
