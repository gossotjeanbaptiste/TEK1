/*
** EPITECH PROJECT, 2024
** Bootstrap-Organized
** File description:
** print_typed_value
*/
#include "../include/my.h"
#include "../include/bootstrap.h"
#include "../include/call.h"

int print_typed_value(void *data, type_t type)
{
    player_t *player;

    if (type == CHAR)
        mini_printf("%c\n", *(char *)data);
    if (type == STRING)
        mini_printf("%s\n", (char *)data);
    if (type == INTEGER)
        mini_printf("%d\n", *(int *)data);
    if (type == PLAYER) {
        player = (player_t *)data;
        mini_printf("%s: lvl.%d\n", player->name, player->lvl);
    }
    return 0;
}
