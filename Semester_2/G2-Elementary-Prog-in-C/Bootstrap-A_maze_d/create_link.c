/*
** EPITECH PROJECT, 2025
** Bootstrap-A_maze_d
** File description:
** create_link
*/
#include <stdlib.h>
#include "graph.h"

link_t *create_link(int data)
{
    link_t *link = malloc(sizeof(link_t));

    if (!link)
        return NULL;
    link->data = data;
    link->next = NULL;
    link->next_count = 0;
    return link;
}
