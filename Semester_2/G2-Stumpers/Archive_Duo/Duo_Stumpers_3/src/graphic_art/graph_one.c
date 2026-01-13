/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** graph_one
*/

#include <stdio.h>
#include <string.h>
#include "../../include/tools.h"

int graph_one(const char c)
{
    char *graph = strdup(" 000 \n0 00 \n  00 \n  00 \n 0000");

    if (!graph)
        return -1;
    print_digit(c, graph);
    return 0;
}
