/*
** EPITECH PROJECT, 2025
** /home/elouan/maze/src/parcour
** File description:
** if you code on paper, you're not a real programmer
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my.h"

static void push(stack_node_t **stack, room_t *room)
{
    stack_node_t *new_node = malloc(sizeof(*new_node));

    if (!new_node)
        return;
    new_node->room = room;
    new_node->next = *stack;
    *stack = new_node;
}

static room_t *pop(stack_node_t **stack)
{
    stack_node_t *top = *stack;
    room_t *room = top->room;

    if (!*stack)
        return NULL;
    *stack = top->next;
    free(top);
    return room;
}

static void process_connections(connection_t *conn,
    memory_t *memory, stack_node_t *stack)
{
    while (conn != NULL) {
        if (!is_visited(memory, conn->room->data))
            push(&stack, conn->room);
        conn = conn->next;
    }
}

static void connect_everything(maze_t *maze)
{
    for (connection_list_t *tmp = maze->connection_list;
        tmp; tmp = tmp->next) {
        connect_rooms(maze, maze->room_list, tmp->room1, tmp->room2);
    }
}

void parcour(maze_t *maze, room_t *start_room, memory_t *memory)
{
    stack_node_t *stack = NULL;
    room_t *current_room;
    connection_t *conn;

    connect_everything(maze);
    push(&stack, start_room);
    while (stack != NULL) {
        current_room = pop(&stack);
        if (is_visited(memory, current_room->data))
            continue;
        mini_printf("%s\n", current_room->data);
        register_room(&memory, current_room->data);
        conn = current_room->connections;
        process_connections(conn, memory, stack);
    }
}
