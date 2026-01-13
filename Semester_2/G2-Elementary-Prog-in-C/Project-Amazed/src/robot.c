/*
** EPITECH PROJECT, 2025
** src/robot
** File description:
** r/ProgrammerHumor
*/

#include "../include/struct.h"
#include <stdlib.h>

static void push_robot(robot_t **stack, int robot_nb, int start_position)
{
    robot_t *new_node = malloc(sizeof(robot_t));

    if (!new_node)
        return;
    new_node->nb = robot_nb;
    new_node->position = start_position;
    new_node->next = *stack;
    *stack = new_node;
}

robot_t *generate_robot_list(maze_t *maze)
{
    robot_t *robot_list = NULL;

    for (int i = maze->nb_robots; i > 0; i++) {
        push_robot(&robot_list, i, maze->start_nb);
    }
    return robot_list;
}
