/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** aff
*/

#include "../../include/my.h"
#include "../../include/corewar.h"

void aff(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    int reg = get_arg_value(global, REG, address + 2, prog);
    char c = reg % 256;

    my_putchar(c);
    prog->carry = (c == 0) ? 1 : 0;
    add_pc(&prog->pc, 3);
}
