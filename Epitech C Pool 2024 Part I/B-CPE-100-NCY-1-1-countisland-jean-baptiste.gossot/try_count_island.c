/*
** EPITECH PROJECT, 2024
** try_count_island
** File description:
** fichier d'essai du count island
*/

#include "include/my.h"
#include "include/function.h"

int get_x(char **world)
{
    int i = 0;

    while (world[0][i] != 0) {
        i++;
    }
    return i;
}

int get_y(char **world)
{
    int i = 0;

    while (world[i] != 0) {
        i++;
    }
    return i;
}

int position_checker(char **world, int x, int y, int count)
{
    int maximum_x = get_x(world) - 1;
    int maximum_y = get_y(world) - 1;

    if (x <= maximum_x && y <= maximum_y && x >= 0 && y >= 0) {
        if (world[x][y] == 'X') {
            world[x][y] = '0' + count;
            del_around(world, y, x, count);
        }
    }
}

int annexe_count_island(char **world, int x, int y)
{
    int count = 0;

    if (world[y][x] == 'X') {
        del_around(world, x, y, count);
        count++;
    }
    return count;
}

int count_island(char **world)
{
    int height = get_x(world);
    int width = get_y(world);
    int count = 0;

    if (height == 0 || width == 0) {
        return 0;
    }
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            annexe_count_island(world, x, y);
        }
    }
    return count;
}
