/*
** EPITECH PROJECT, 2025
** clean string (solo stumper 1)
** File description:
** clean_str
*/

#include "../include/my.h"

int count_space(char *str)
{
    int len = my_strlen(str);
    int space_count = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
    }
    return space_count;
}

int *position(char *str)
{
    int *position = {};
    int i = 0;
    int n = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            position[n] = i;
            n++;
        }
        i++;
    }
    return position;
}

void clean_str(char *str)
{
    int len = my_strlen(str);
    char **array;
    int *position_array = position(str);
    int j;

    while (str[j] != '\0') {
        for (int i = 0; position_array[i]; i++) {
            array[i] = annexe_clean_str(j, i, position_array, str);
        }
        j++;
    }
    my_putchar('\n');
}

char *annexe_clean_str(int j, int i, int *position_array, char *str)
{
    char *word;

    if (j > position_array[i] &&
        str[j] == ' ' || str[j] == '\t') {
        for (int k = j; k <= position_array[i]; k++) {
            word = strncopy_index(str, position_array[i], j);
        }
    }
    return word;
}
