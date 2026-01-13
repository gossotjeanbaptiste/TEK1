/*
** EPITECH PROJECT, 2025
** Project-Robot_Factory
** File description:
** trim_trail_whitespace
*/
#include "../include/my.h"
#include "../include/corewar.h"
extern const op_t op_tab[];

void trim_trailing_whitespace(char *str)
{
    int len = my_strlen(str);

    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t')) {
        str[len - 1] = '\0';
        len--;
    }
}
