/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** graph_zero
*/

#include <stdio.h>
#include <string.h>
#include "../../include/tools.h"

int graph_zero(const char c)
{
    char *graph = strdup(" 000 \n0   0\n0   0\n0   0\n 000");

    if (!graph)
        return -1;
    print_digit(c, graph);
    return 0;
}
