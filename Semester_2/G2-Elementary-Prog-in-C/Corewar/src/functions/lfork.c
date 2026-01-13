/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** lfork
*/

#include "../../include/corewar.h"

void ex_lfork(global_t *global, prog_t *prog)
{
    int address = prog->pc + get_2bytes_arg(global, prog->pc + 1);
    prog_t new_prog;

    new_prog.pc = select_address(address);
    new_prog.carry = 0;
    global->nbr_cycle_dump++;
    new_prog.id = global->nbr_cycle_dump;
    new_prog.live_call_cyle = 0;
    new_prog.address = -1;
    new_prog.size = 0;
    new_prog.content = NULL;
    new_prog.registers = malloc(sizeof(int) * REG_NUMBER);
    if (new_prog.registers == NULL)
        return;
    for (int i = 0; i < REG_NUMBER; i++)
        new_prog.registers[i] = 0;
    add_prog(global, &new_prog);
}
