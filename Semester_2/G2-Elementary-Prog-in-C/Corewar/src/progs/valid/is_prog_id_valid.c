/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** tools_bis
*/

#include "../../../include/my.h"
#include "../../../include/corewar.h"

int is_prog_id_valid(global_t *global, long id)
{
    if (global->progs == NULL)
        return 1;
    for (int i = 0; global->progs[i] == NULL; i++) {
        if (global->progs[i]->id == id)
            return 0;
    }
    if (id < 0)
        return 0;
    return 1;
}
