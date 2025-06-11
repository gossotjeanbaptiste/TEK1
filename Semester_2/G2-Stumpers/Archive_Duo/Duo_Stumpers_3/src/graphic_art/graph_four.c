/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** graph_four
*/

#include <stdio.h>
#include <string.h>
#include "../../include/tools.h"

int graph_four(const char c)
{
    char *graph = strdup("  00 \n 0 0 \n0  0 \n00000\n   0 \n");

    if (!graph)
        return -1;
    print_digit(c, graph);
    return 0;
}
