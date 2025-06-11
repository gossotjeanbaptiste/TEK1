/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** graph_three
*/

#include <stdio.h>
#include <string.h>
#include "../../include/tools.h"

int graph_three(const char c)
{
    char *graph = strdup("0000 \n    0\n 000 \n    0\n0000 \n");

    if (!graph)
        return -1;
    print_digit(c, graph);
    return 0;
}
