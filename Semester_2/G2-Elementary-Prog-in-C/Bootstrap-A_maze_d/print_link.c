/*
** EPITECH PROJECT, 2025
** Bootstrap-A_maze_d
** File description:
** print_link
*/

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void print_link(link_t *link)
{
    if (link == NULL) {
        print("Link is NULL\n");
        return;
    }
    printf("%d\n", link->data);
}
