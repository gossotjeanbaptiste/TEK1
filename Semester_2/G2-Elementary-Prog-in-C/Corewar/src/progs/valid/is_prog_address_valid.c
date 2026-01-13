/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** tools_bis
*/

#include "../../../include/my.h"
#include "../../../include/corewar.h"


int is_prog_address_valid(global_t *global, int address)
{
    if (global->progs == NULL)
        return 1;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address == address)
            return 0;
    }
    return 1;
}
