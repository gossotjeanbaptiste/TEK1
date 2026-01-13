/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** add_line
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>

static void add_line(sfVertexArray *vertexArray, sfVector2f p1, sfVector2f p2)
{
    sfVertex line[] = {{p1, sfBlack, {0, 0}}, {p2, sfBlack, {0, 0}}};

    sfVertexArray_append(vertexArray, line[0]);
    sfVertexArray_append(vertexArray, line[1]);
}

static void adder_condition(int y, int x,
    sfVertexArray *vertexArray, point_t *point)
{
    if (map[y][x] == 0 && map[y][x + 1] == 0)
        add_line(vertexArray, point->p2, point->p5);
    if (map[y][x] == 0 && map[y + 1][x] == 0)
        add_line(vertexArray, point->p3, point->p6);
    if (map[y][x + 1] == 0 && map[y + 1][x + 1] == 0
        && x < MAP_X - 1 && y < MAP_Y - 1)
        add_line(vertexArray, point->p2, point->p4);
    if (map[y + 1][x] == 0 && map[y + 1][x + 1] == 0
        && x < MAP_X - 1 && y < MAP_Y - 1)
        add_line(vertexArray, point->p3, point->p4);
    if (map[y + 1][x + 1] == 0 && map[y][x + 1] == 0
        && x < MAP_X - 1 && y < MAP_Y - 1)
        add_line(vertexArray, point->p4, point->p7);
}

void adder(sfVector2f points[12][12][2], sfVertexArray *vertexArray)
{
    point_t *point = malloc(sizeof(point_t));

    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 11; x++) {
            point->p1 = points[y][x][0];
            point->p2 = points[y][x + 1][1];
            point->p3 = points[y + 1][x][1];
            point->p4 = points[y + 1][x + 1][1];
            point->p5 = points[y][x + 1][0];
            point->p6 = points[y + 1][x][0];
            point->p7 = points[y + 1][x + 1][0];
            add_line(vertexArray, point->p1, point->p5);
            add_line(vertexArray, point->p1, point->p6);
            add_line(vertexArray, point->p5, point->p7);
            add_line(vertexArray, point->p6, point->p7);
            adder_condition(y, x, vertexArray, point);
        }
    }
    free(point);
}
