/*
** EPITECH PROJECT, 2025
** /home/elouan/maze/src/memory
** File description:
** hello world?
*/


#include "../include/struct.h"
#include <stdlib.h>
#include "../include/my.h"

void push_connection(connection_list_t **connection, char *a, char *b)
{
    connection_list_t *new_entry = malloc(sizeof(*new_entry));

    if (!new_entry)
        return;
    new_entry->room1 = my_strdup(a);
    new_entry->room2 = my_strdup(b);
    new_entry->next = *connection;
    *connection = new_entry;
    return;
}

int is_visited(memory_t *memory, char *room_name)
{
    for (memory_t *tmp = memory; tmp; tmp = tmp->next) {
        if (!my_strcmp(tmp->room_visited, room_name))
            return 1;
    }
    return 0;
}

int register_room(memory_t **memory, char *room_nb)
{
    memory_t *new_entry = malloc(sizeof(*new_entry));

    if (!new_entry)
        return 1;
    new_entry->room_visited = room_nb;
    new_entry->next = *memory;
    *memory = new_entry;
    return 0;
}
