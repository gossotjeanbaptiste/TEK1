/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** test_place
*/

#include "../../include/corewar.h"

int test_place(prog_t *progp, prog_t *prog, int address)
{
    for (int j = progp->address; j < progp->address + progp->size; j++) {
        if (j >= address && j <= address + prog->size)
            return 0;
    }
    return 1;
}
