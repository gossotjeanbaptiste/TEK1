/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** progs_placer
*/

#include <stdio.h>
#include "../../include/corewar.h"

static void place_prog_at(global_t *global, prog_t *prog, int address)
{
    for (int i = 0; i < prog->size; i++)
        global->memory[select_address(i + address)] = prog->content[i];
    prog->address = address;
}

static int find_next_address(global_t *global, prog_t *prog, int start,
    int space)
{
    int address = start;

    while (!can_place_prog(global, prog, address))
        address++;
    return (address == 0) ? address : address + space;
}

static void place_normal(global_t *global, int space)
{
    int address = 0;

    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address == -1) {
            address = find_next_address(global, global->progs[i],
                address, space);
            place_prog_at(global, global->progs[i], address);
            address += global->progs[i]->size;
        }
    }
}

void place_progs(global_t *global)
{
    int empty = MEM_SIZE;
    int space;

    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address != -1 && !can_place_prog(global,
        global->progs[i], global->progs[i]->address))
            return;
        if (global->progs[i]->address != -1) {
            empty -= global->progs[i]->size;
            place_prog_at(global, global->progs[i],
            global->progs[i]->address);
        }
    }
    space = empty / get_progs_size(global);
    place_normal(global, space);
}
