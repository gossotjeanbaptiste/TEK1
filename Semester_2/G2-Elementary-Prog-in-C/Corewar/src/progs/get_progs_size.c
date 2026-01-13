/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** get_progs_size
*/

#include "../../include/corewar.h"

int get_progs_size(global_t *global)
{
    int size = 0;

    if (global->progs == NULL)
        return 0;
    for (; global->progs[size] != NULL; size++);
    return size;
}
