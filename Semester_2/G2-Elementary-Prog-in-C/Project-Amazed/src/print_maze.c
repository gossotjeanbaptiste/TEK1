/*
** EPITECH PROJECT, 2025
** print_maze
** File description:
** print_maze
*/

#include "../include/struct.h"
#include <unistd.h>
#include "../include/my.h"

room_list_t *rrl(room_list_t *list)
{
    room_list_t *new_list = 0;

    for (room_list_t *tmp = list; tmp; tmp = tmp->next) {
        add_room_to_list(&new_list, tmp->room);
    }
    return new_list;
}

static connection_list_t *rcl(connection_list_t *list)
{
    connection_list_t *new_list = 0;

    for (connection_list_t *tmp = list; tmp; tmp = tmp->next) {
        push_connection(&new_list, tmp->room1, tmp->room2);
    }
    return new_list;
}

static void print_room_line(room_t *room)
{
    my_putstr(room->data);
    my_putstr(" ");
    my_put_nbr(room->x);
    my_putstr(" ");
    my_put_nbr(room->y);
    my_putstr("\n");
}

static void print_room_block(room_list_t *list, char *target, char *label)
{
    for (room_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (target && my_strcmp(tmp->room->data, target) == 0) {
            my_putstr(label);
            my_putstr("\n");
            print_room_line(tmp->room);
            return;
        }
    }
}

static void print_all_other_rooms(room_list_t *list, maze_t *maze)
{
    for (room_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (maze->start_name &&
            my_strcmp(tmp->room->data, maze->start_name) == 0)
            continue;
        if (maze->end_name &&
            my_strcmp(tmp->room->data, maze->end_name) == 0)
            continue;
        print_room_line(tmp->room);
    }
}

static void print_rooms(maze_t *maze)
{
    my_putstr("#rooms\n");
    print_room_block(maze->room_list, maze->start_name, "##start");
    print_room_block(maze->room_list, maze->end_name, "##end");
    print_all_other_rooms(maze->room_list, maze);
}

static void print_tunnels(maze_t *maze)
{
    my_putstr("#tunnels\n");
    for (connection_list_t *t = rcl(maze->connection_list); t; t = t->next) {
        my_putstr(t->room1);
        my_putstr("-");
        my_putstr(t->room2);
        my_putstr("\n");
    }
}

void print_maze(maze_t *maze)
{
    my_putstr("#number_of_robots\n");
    my_put_nbr(maze->nb_robots);
    my_putstr("\n");
    print_rooms(maze);
    print_tunnels(maze);
}
