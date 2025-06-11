/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** utils
*/

#include "../../../include/corewar.h"

int get_2bytes_arg(global_t *global, int address)
{
    int value = global->memory[select_address(address)] & 255;

    value = ((value << 8) & 65280) +
    (global->memory[select_address(address + 1)] & 255);
    return value;
}
