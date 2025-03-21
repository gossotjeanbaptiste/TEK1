/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** compare two strings but only for n bytes
*/
#include "my.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}
