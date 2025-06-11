/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** get_command_duration
*/
#include "../../../include/corewar.h"

int get_command_duration(int id)
{
    if (id < 1 || id > 16)
        return (-1);
    return COMMANDS[id - 1].duration;
}
