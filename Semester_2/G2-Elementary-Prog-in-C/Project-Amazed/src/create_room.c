/*
** EPITECH PROJECT, 2025
** src/create_room
** File description:
** Room creation and link connection
*/

#include "../include/struct.h"
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

room_t *create_room(char *data, int x, int y)
{
    room_t *room = malloc(sizeof(*room));

    if (!room)
        return NULL;
    room->data = my_strdup(data);
    room->x = x;
    room->y = y;
    room->connections = NULL;
    return room;
}

int add_room_to_list(room_list_t **list, room_t *room)
{
    room_list_t *new_entry = malloc(sizeof(*new_entry));

    if (!new_entry)
        return 1;
    new_entry->room = room;
    new_entry->next = *list;
    *list = new_entry;
    return 0;
}

static int connect_links(room_t *link1, room_t *link2)
{
    connection_t *conn1 = malloc(sizeof(*conn1));
    connection_t *conn2 = malloc(sizeof(*conn2));

    if (!conn1 || !conn2) {
        free(conn1);
        free(conn2);
        return 1;
    }
    conn1->room = link2;
    conn1->next = link1->connections;
    link1->connections = conn1;
    conn2->room = link1;
    conn2->next = link2->connections;
    link2->connections = conn2;
    return 0;
}

static room_t *find_room(room_list_t *list, char *name)
{
    for (room_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (!my_strcmp(tmp->room->data, name))
            return list->room;
    }
    return NULL;
}

int connect_rooms(maze_t *maze, room_list_t *list, char *name1, char *name2)
{
    room_t *room1 = find_room(list, name1);
    room_t *room2 = find_room(list, name2);

    if (!room1 || !room2)
        return 1;
    push_connection(&maze->connection_list, name1, name2);
    return connect_links(room1, room2);
}
