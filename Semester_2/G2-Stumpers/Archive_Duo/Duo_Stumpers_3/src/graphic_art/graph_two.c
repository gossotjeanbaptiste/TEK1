/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** graph_two
*/

#include <stdio.h>
#include <string.h>
#include "../../include/tools.h"

int graph_two(const char c)
{
    char *graph = strdup(" 000 \n0   0\n   0 \n 0   \n00000");

    if (!graph)
        return -1;
    print_digit(c, graph);
    return 0;
}
