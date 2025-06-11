/*
** EPITECH PROJECT, 2025
** Project-Robot_Factory
** File description:
** triming
*/

#include "../include/my.h"
#include "../include/corewar.h"
extern const op_t op_tab[];

void trim_newline(char *str)
{
    char *pos = my_strchr(str, '\n');

    if (pos)
        *pos = '\0';
}
