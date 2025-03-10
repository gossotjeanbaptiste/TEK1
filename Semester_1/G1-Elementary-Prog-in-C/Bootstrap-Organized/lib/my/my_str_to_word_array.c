/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** splits string into words and return an array of that
*/
#include <stdlib.h>
#include "my.h"

char **my_str_to_word_array(char *str)
{
    int len_str = my_strlen(str);
    char **tableau = malloc(sizeof(char) * (len_str + 1));

    for (int i = 0; i != len_str; i++) {
        if (str[i] < 47 && str[i] > 58)
            tableau[i] = &str[i];
        if (str[i] < 64 && str[i] > 91)
            tableau[i] = &str[i];
        if (str[i] < 96 && str[i] > 123)
            tableau[i] = &str[i];
    }
    return tableau;
}
