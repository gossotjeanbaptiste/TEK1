/*
** EPITECH PROJECT, 2025
** Bootstrap-A_maze_d
** File description:
** connect_links
*/
#include <stdlib.h>
#include "graph.h"

void connect_links(link_t *link1, link_t *link2)
{
    if (link1 == NULL || link2 == NULL)
        return;
    link1->next =
    realloc(link1->next, sizeof(link_t *) * (link1->next_count + 1));
    if (link1->next == NULL)
        return;
    link1->next[link1->next_count] = link2;
    link1->next_count++;
}
