/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** live
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/corewar.h"

static void show_alive(prog_t *prog, global_t *global)
{
    mini_printf("The player %d (%s)is alive.\n", prog->id, prog->name);
    if (global->last_alive != NULL)
        free(global->last_alive);
    global->last_alive = my_strdup(prog->name);
    global->last_live_id = prog->id;
}

void live(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    long arg = get_4bytes_arg(global, address + 1);

    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->id == arg)
            global->progs[i]->live_call_cyle = global->cycle;
    }
    add_pc(&prog->pc, 5);
    if (arg == prog->id)
        show_alive(prog, global);
    global->live_calls += 1;
    if (global->live_calls >= NBR_LIVE) {
        global->live_calls = 0;
        global->cycles_to_die -= CYCLE_DELTA;
    }
}
