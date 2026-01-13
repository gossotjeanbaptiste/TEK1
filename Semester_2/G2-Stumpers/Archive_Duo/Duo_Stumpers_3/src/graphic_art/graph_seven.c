/*
** EPITECH PROJECT, 2025
** crocus
** File description:
** graphic_seven
*/

#include <stdio.h>
#include <string.h>
#include "../../include/tools.h"

int graph_seven(const char c)
{
    char *graph = strdup("00000\n    0\n   0 \n  0  \n 0   \n");

    if (!graph)
        return -1;
    print_digit(c, graph);
    return 0;
}
