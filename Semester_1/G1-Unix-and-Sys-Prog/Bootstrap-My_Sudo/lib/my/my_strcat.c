/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** concatenates two strings
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0') {
        a++;
    }
    while (src[b] != '\0') {
        dest[a] = src[b];
        b++;
    }
    return dest;
}
