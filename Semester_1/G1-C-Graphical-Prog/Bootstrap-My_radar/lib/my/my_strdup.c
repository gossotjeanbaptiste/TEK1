/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** reproduce the usage of strdup function
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int len_src = my_strlen(src);
    char *str = malloc(sizeof(char) * (len_src + 1));

    for (int i = 0; i < len_src; i++) {
        str[i] = src[i];
    }
    str[len_src] = '\0';
    return str;
}
