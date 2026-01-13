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
    int size = 0;
    int max_size = 0;
    int i = 0;

    while (map->row + size < map->nb_rows && map->col + size < map->nb_cols) {
        i = map->row;
        if (annexe_un_find_biggest_square(map, max_size, size, i) != size) {
            return max_size;
        }
        max_size = size;
        size++;
    }
    return max_size;
}

int annexe_un_find_biggest_square(map_t *map, int max_size, int size, int i)
{
    while (i <= map->row + size) {
        if (annexe_deux_find_biggest_square(map, size, i) != size) {
            return max_size;
        }
        i++;
    }
}
int annexe_deux_find_biggest_square(map_t *map, int size, int i)
{
    int j = map->col;

    while (j <= map->col + size) {
        if (map->array[i][j] == 'o')
            return (size);
        j++;
    }
}
