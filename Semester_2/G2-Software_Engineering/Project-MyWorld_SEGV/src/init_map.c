/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** init_map
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>

int init_map(map_t *map, int size)
{
    map->size = size;
    map->map = malloc(size * sizeof(int *));
    map->points = malloc(size * sizeof(sfVector2f **));
    if (!map->map || !map->points)
        return 84;
    for (int i = 0; i < size; i++) {
        map->map[i] = malloc(size * sizeof(int));
        map->points[i] = malloc(size * sizeof(sfVector2f *));
        if (!map->map[i] || !map->points[i])
            return 84;
        for (int j = 0; j < size; j++) {
            map->points[i][j] = malloc(2 * sizeof(sfVector2f));
            if (!map->points[i][j])
                return 84;
        }
    }
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            map->map[y][x] = 0;
        }
    }
    return 0;
}
