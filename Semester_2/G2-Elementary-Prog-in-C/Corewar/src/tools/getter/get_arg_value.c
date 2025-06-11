/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** get_arg_value
*/

#include "../../../include/corewar.h"

long get_arg_value(global_t *global, arg_type_t type,
    int address, prog_t *prog)
{
    if (type == REG)
        return (prog->registers[global->memory[select_address(address)] - 1]);
    if (type == IND)
        return (get_4bytes_arg(global, select_address(
        get_2bytes_arg(global, address) + prog->address + prog->pc)));
    if (type == DIR2)
        return (get_2bytes_arg(global, address));
    return get_4bytes_arg(global, address);
}
