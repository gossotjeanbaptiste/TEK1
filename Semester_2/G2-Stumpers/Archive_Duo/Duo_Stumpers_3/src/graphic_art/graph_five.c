/*
** EPITECH PROJECT, 2025
** crocus
** File description:
** graph_five
*/

#include <stdio.h>
#include <string.h>
#include "../../include/tools.h"

int graph_five(const char c)
{
    char *graph = strdup("00000\n0    \n0000 \n    0\n0000 \n");

    if (!graph)
        return -1;
    print_digit(c, graph);
    return 0;
}
