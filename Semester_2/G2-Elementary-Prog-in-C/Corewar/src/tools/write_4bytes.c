/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** write_4bytes
*/

#include "../../include/corewar.h"

void write_4bytes(global_t *global, int address, int value)
{
    int val1 = (value >> 24) & 255;
    int val2 = (value >> 16) & 255;
    int val3 = (value >> 8) & 255;
    int val4 = value & 255;

    global->memory[select_address(address)] = val1;
    global->memory[select_address(address + 1)] = val2;
    global->memory[select_address(address + 2)] = val3;
    global->memory[select_address(address + 3)] = val4;
}
