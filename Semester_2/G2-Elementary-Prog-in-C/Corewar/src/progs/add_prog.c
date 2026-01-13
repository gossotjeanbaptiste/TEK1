/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** add_prog
*/

#include "../../include/corewar.h"

void add_prog(global_t *global, prog_t *prog)
{
    int size = get_progs_size(global);
    prog_t **new = malloc(sizeof(prog_t *) * (size + 2));

    new[size + 1] = NULL;
    new[size] = prog;
    if (global->progs == NULL) {
        global->progs = new;
        return;
    }
    for (int i = 0; i < size; i++)
        new[i] = global->progs[i];
    free(global->progs);
    global->progs = new;
}
