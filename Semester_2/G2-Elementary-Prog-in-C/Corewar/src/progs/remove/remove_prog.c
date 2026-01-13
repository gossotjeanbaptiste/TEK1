/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** remove_prog
*/

#include "../../../include/corewar.h"

void remove_prog(global_t *global, prog_t *prog)
{
    int size = get_progs_size(global);
    prog_t **new = malloc(sizeof(prog_t *) * size);
    int index = 0;

    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i] != prog) {
            new[index] = global->progs[i];
            index++;
        }
    }
    free(prog->content);
    free(prog->registers);
    free(prog);
    new[index] = NULL;
    free(global->progs);
    global->progs = new;
}
