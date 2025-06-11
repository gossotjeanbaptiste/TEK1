/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** progs_manager
*/

#include <stdlib.h>
#include "../../../include/corewar.h"

int get_first_valid_id(global_t *global)
{
    int id = 0;

    if (global->progs == NULL)
        return 0;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->id == id)
            id++;
    }
    return id;
}
