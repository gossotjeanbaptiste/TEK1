/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** tools_bis
*/

#include "../../../include/my.h"
#include "../../../include/corewar.h"


void remove_all_progs(global_t *global)
{
    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++)
        remove_prog(global, global->progs[i]);
}
