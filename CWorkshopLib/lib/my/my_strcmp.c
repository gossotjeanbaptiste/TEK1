/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare two strings
*/
#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    if (len_s1 == len_s2)
        return 0;
    if (len_s1 < len_s2)
        return -1;
    if (len_s1 > len_s2)
        return 1;
    return 0;
}
