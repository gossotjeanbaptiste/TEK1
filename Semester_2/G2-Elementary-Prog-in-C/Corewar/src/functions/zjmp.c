/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** zjmp
*/

#include <stdio.h>
#include "../../include/corewar.h"

void zjmp(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    int add = get_2bytes_arg(global, address + 1);

    if (prog->carry)
        add_pc(&prog->pc, add);
    else
        add_pc(&prog->pc, 3);
}
