/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** tools
*/

#include "../../../include/corewar.h"

int get_execute_address(prog_t *prog)
{
    int address = prog->address + prog->pc;

    return select_address(address);
}
