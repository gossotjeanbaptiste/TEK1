/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare two strings
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;
    char cmp;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            cmp = (char)((unsigned char)s1[i] - (unsigned char)s2[i]);
            return (cmp > 0) * 2 - 1;
        }
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return -1;
    if (s1[i] != '\0' && s2[i] == '\0')
        return 1;
    return (0);
}
