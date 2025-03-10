/*
** EPITECH PROJECT, 2024
** concat_params
** File description:
** turns all the arguments from a
** single line str into a separated str
*/
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

char *concat_params(int argc, char **argv)
{
    int total_len = 0;
    char *str = malloc(sizeof(char) * (total_len + 1) + argc);
    int len = 0;
    int c = 0;

    for (int i = 0; i < argc; i++)
        total_len += my_strlen(argv[0]);
    for (int j = 0; j < argc; j++) {
        len = my_strlen(argv[j]);
        for (int k = 0; k < len; k++) {
            str[c] = argv[j][k];
            c++;
        }
        str[c] = '\n';
        c++;
    }
    str[total_len] = '\0';
    return str;
}
