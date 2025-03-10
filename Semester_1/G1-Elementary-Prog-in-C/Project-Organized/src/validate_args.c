/*
** EPITECH PROJECT, 2025
** Project-Organized
** File description:
** validate_args
*/
#include "../include/my.h"
#include "../include/shell.h"

int validate_args(void *data, char **args)
{
    if (!data || !args[0])
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (!is_number(args[i]))
            return 84;
    }
    return 0;
}
