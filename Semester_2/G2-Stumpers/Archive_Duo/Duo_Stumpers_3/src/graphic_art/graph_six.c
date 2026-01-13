/*
** EPITECH PROJECT, 2025
** crocus
** File description:
** graphic_six
*/

#include <stdio.h>
#include <string.h>
#include "../../include/tools.h"

int graph_six(const char c)
{
    char *graph = strdup(" 000 \n0    \n0000 \n0   0\n 000 \n");

    if (!graph)
        return -1;
    print_digit(c, graph);
    return 0;
}
