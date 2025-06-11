/*
** EPITECH PROJECT, 2025
** Bootstrap-A_maze_d
** File description:
** print_data_of_connected_links
*/

#include <stdio.h>
#include "graph.h"

void print_data_of_connected_links(link_t *link)
{
    if (link == NULL) {
        printf("Link is NULL\n");
        return;
    }
    for (int i = 0; i < link->next_count; i++) {
        printf("%d\n", link->next[i]->data);
    }
}
