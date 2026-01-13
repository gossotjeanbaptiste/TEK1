/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** find_biggest_square
*/
#include "../include/struct.h"
#include "../include/call.h"
#include "../include/my.h"

int find_biggest_square(map_t *map)
{
    int max_size = 0;
    int size = 0;

    for (int i = 0; i < map->nb_rows; i++) {
        size = annexe_un_find_biggest_square(map, max_size, size, i);
        if (size > max_size)
            max_size = size;
    }
    return max_size;
}

int annexe_un_find_biggest_square(map_t *map, int max_size, int size, int i)
{
    for (int j = 0; j < map->nb_cols; j++) {
        size = annexe_deux_find_biggest_square(map, size, i);
        if (size > max_size)
            max_size = size;
    }
    return size;
}

int annexe_deux_find_biggest_square(map_t *map, int size, int i)
{
    if (map->array[i][0] == '.')
        size = 1;
    return size;
}
