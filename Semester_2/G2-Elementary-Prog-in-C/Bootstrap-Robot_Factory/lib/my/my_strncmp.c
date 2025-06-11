/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** compare two strings but only for n bytes
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) {
        return 0;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}
