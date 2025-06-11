/*
** EPITECH PROJECT, 2025
** Bootstrap-MyWorld
** File description:
** draw_2d_map
*/
#include "../include/csfml_include.h"

static void vertex_verifier
(int x, sfVector2f **map_2d, int y, sfRenderWindow *window)
{
    sfVertexArray *line;

    if (x < MAP_X - 1) {
        line = create_line(&map_2d[y][x], &map_2d[y][x + 1]);
        sfRenderWindow_drawVertexArray(window, line, NULL);
        sfVertexArray_destroy(line);
    }
    if (y < MAP_Y - 1) {
        line = create_line(&map_2d[y][x], &map_2d[y + 1][x]);
        sfRenderWindow_drawVertexArray(window, line, NULL);
        sfVertexArray_destroy(line);
    }
}

int draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d)
{
    if (!window || !map_2d)
        return -1;
    for (int y = 0; y < MAP_Y; y++) {
        for (int x = 0; x < MAP_X; x++) {
            vertex_verifier(x, map_2d, y, window);
        }
    }
    return 0;
}
