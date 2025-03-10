/*
** EPITECH PROJECT, 2024
** Bootstrap-Organized
** File description:
** main
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "include/call.h"

int compare_function(void *data, void *ref)
{
    player_t *player = (player_t *)data;

    if (data == NULL || ref == NULL) {
        return 84;
    }
    if (player->name == NULL) {
        return 84;
    }
    return my_strcmp(player->name, (char *)ref);
}

void display_function(void *data)
{
    player_t *player = (player_t *)data;

    if (data == NULL) {
        return;
    }
    if (player->name == NULL) {
        return;
    }
    my_putstr(player->name);
    my_putchar('\n');
}

int main(void)
{
    linked_list_t *list = NULL;
    player_t player1 = { .name = "Player1" };
    player_t player2 = { .name = "Player2" };

    push_to_list(&list, &player1);
    push_to_list(&list, &player2);
    delete_in_list(&list, &player1, &compare_function);
    display_list(list, &display_function);
    return 0;
}
