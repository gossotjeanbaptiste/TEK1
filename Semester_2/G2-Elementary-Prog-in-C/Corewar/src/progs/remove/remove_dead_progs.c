/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** tools_bis
*/

#include "../../../include/my.h"
#include "../../../include/corewar.h"

void remove_dead_progs(global_t *global)
{
    int redo = 0;

    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (ABS(global->cycle - global->progs[i]->live_call_cyle) >
        global->cycles_to_die) {
            remove_prog(global, global->progs[i]);
            redo = 1;
            break;
        }
    }
    if (redo)
        remove_dead_progs(global);
}
