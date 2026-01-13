/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** write_new_pc
*/

#include "../../include/corewar.h"

void write_new_pc(prog_t *prog, arg_type_t args[3], int has_ocp)
{
    int add = 1;

    for (int i = 0; i < 3; i++) {
        if (args[i] == NO)
            continue;
        add = (args[i] == REG) ? (add + T_REG) : add;
        add = (args[i] == IND) ? (add + T_IND) : add;
        add = (args[i] == DIR2) ? (add + T_DIR2) : add;
        add = (args[i] == DIR4) ? (add + T_DIR4) : add;
    }
    add = (has_ocp) ? (add + 1) : add;
    add_pc(&prog->pc, add);
}
