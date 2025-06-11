/*
** EPITECH PROJECT, 2025
** solo stumper 2
** File description:
** case sensitive anagram
*/
#include "../include/my.h"

char *case_sensitive(char *str)
{
    int i = 0;
    char *new_str[my_strlen(str)];
    char c;

    while (str[i] != '\0') {
        c = str[i];
        if (c <= 65 && c >= 90) {
            *new_str[i] = str[i] + 32;
        } else {
            new_str[i] = &str[i];
        }
        i++;
    }
    return str;
}
