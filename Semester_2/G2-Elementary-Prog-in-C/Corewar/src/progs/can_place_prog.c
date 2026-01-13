/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** can_place_prog
*/

#include "../../include/corewar.h"

int can_place_prog(global_t *global, prog_t *prog, int address)
{
    if (global->progs == NULL)
        return 1;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address == -1)
            continue;
        if (!test_place(global->progs[i], prog, address))
            return 0;
    }
    return 1;
}
