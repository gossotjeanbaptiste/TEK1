/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** utils
*/

#include "../../../include/corewar.h"

long get_4bytes_arg(global_t *global, int address)
{
    int value = global->memory[select_address(address)];

    for (int i = 1; i < 4; i++)
        value = (value << 8) + global->memory[select_address(address + i)];
    return value;
}
