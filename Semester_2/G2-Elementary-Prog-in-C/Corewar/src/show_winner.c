/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** show_winner
*/

#include "../include/corewar.h"
#include "../include/my.h"

void show_winner(global_t *global)
{
    if (global->last_alive == NULL) {
        mini_printf("No winner !\n");
        return;
    }
    mini_printf("The player %d (%s)has won.\n", global->last_live_id,
        global->last_alive);
    free(global->last_alive);
}
