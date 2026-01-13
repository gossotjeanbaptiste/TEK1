/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** tools
*/

#include "../../include/corewar.h"

int select_address(int address)
{
    while (address >= MEM_SIZE)
        address -= MEM_SIZE;
    while (address < 0)
        address += MEM_SIZE;
    return address;
}
