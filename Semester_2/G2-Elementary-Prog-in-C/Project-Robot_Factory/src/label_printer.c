/*
** EPITECH PROJECT, 2025
** Project-Robot_Factory
** File description:
** label_printer
*/
#include "../include/my.h"
#include "../include/corewar.h"
extern const op_t op_tab[];

int label_printer(int *found, char instr[MAX_LINE])
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strcmp(instr, op_tab[i].mnemonique) == 0) {
            *found = 1;
            mini_printf("Instruction: %s (Opcode: %d)\n",
                instr, op_tab[i].nbr_cycles);
            break;
        }
    }
    return *found;
}
