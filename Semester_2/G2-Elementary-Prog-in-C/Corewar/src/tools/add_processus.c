/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** add_processus
*/

#include "../../include/corewar.h"

void add_pc(int *pc, int nb)
{
    *pc += nb;
    while (*pc > 65535)
        *pc -= 65536;
    while (*pc < 0)
        *pc += 65536;
}
