/*
** EPITECH PROJECT, 2025
** Bootstrap-MyWorld
** File description:
** create_2d_map
*/
#include "../include/csfml_include.h"

static sfVector2f **creating_the_map
(map_creator_t *map_create, const int map[MAP_Y][MAP_X])
{
    if (!map_create->map_2d)
        return NULL;
    for (int y = 0; y < MAP_Y; y++) {
        map_create->map_2d[y] = malloc(sizeof(sfVector2f) * MAP_X);
        if (!map_create->map_2d[y])
            return NULL;
        for (int x = 0; x < MAP_X; x++) {
            map_create->z = map[y][x];
            map_create->map_2d[y][x] = project_iso_point
            (x * TILE_SIZE, y * TILE_SIZE, map_create->z * TILE_SIZE);
            map_create->map_2d[y][x].x += map_create->offset_x;
            map_create->map_2d[y][x].y += map_create->offset_y;
        }
    }
    return map_create->map_2d;
}

sfVector2f **create_2d_map(const int map[MAP_Y][MAP_X])
{
    map_creator_t *map_create = malloc(sizeof(map_creator_t));

    map_create->map_2d = malloc(sizeof(sfVector2f *) * MAP_Y);
    map_create->top_left = project_iso_point(0, 0, 0);
    map_create->bottom_right = project_iso_point
    ((MAP_X - 1) * TILE_SIZE, (MAP_Y - 1) * TILE_SIZE, 0);
    map_create->grid_width =
    map_create->bottom_right.x - map_create->top_left.x;
    map_create->grid_height =
    map_create->bottom_right.y - map_create->top_left.y;
    map_create->offset_x = (WINDOW_WIDTH - map_create->grid_width) / 2;
    map_create->offset_y = (WINDOW_HEIGHT - map_create->grid_height) / 2;
    return creating_the_map(map_create, map);
}
