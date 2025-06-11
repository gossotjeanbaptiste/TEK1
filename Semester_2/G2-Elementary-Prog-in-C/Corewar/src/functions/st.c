/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** st
*/

#include "../../include/corewar.h"

void ex_st(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    arg_type_t args[3] = {REG, get_argument_type(global, address, 2), NO};
    int reg = get_arg_value_mod(global, REG, address + 2, prog);
    int arg2 = get_arg_value_mod(global, args[1], address + 3, prog);

    if (args[1] == REG) {
        arg2 = global->memory[select_address(address + 3)];
        prog->registers[arg2 - 1] = reg;
    } else
        write_4bytes(global, select_address(address + arg2 % IDX_MOD), reg);
    prog->carry = (reg == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}
