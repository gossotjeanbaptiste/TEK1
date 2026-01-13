/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** init_map
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>

static int malloc_and_verif_alloc_point(map_t *map, int index, int i)
{
    map->points[index][i] = malloc(map->size * sizeof(sfVector2f));
    if (!map->points[index][i]) {
        for (int j = 0; j < i; j++)
            free(map->points[index][j]);
        free(map->points[index]);
        return 84;
    }
    return 0;
}

static int allocate_points(map_t *map, int index)
{
    if (index >= map->size)
        return 84;
    map->points[index] = malloc(map->size * sizeof(sfVector2f *));
    if (!map->points[index]) {
        return 84;
    }
    for (int i = 0; i < map->size; i++) {
        if (malloc_and_verif_alloc_point(map, index, i) == 84)
            return 84;
    }
    return 0;
}

static void free_points(map_t *map, int index)
{
    for (int i = 0; i < map->size; i++) {
        free(map->points[index][i]);
    }
    free(map->points[index]);
}

static void initialize_points(map_t *map)
{
    for (int y = 0; y < map->size; y++) {
        for (int x = 0; x < map->size; x++) {
            map->points[0][y][x] = (sfVector2f){0, 0};
            map->points[1][y][x] = (sfVector2f){0, 0};
        }
    }
}

int init_points(map_t *map)
{
    if (allocate_points(map, 0) == 84) {
        return 84;
    }
    if (allocate_points(map, 1) == 84) {
        free_points(map, 0);
        return 84;
    }
    initialize_points(map);
    return 0;
}
