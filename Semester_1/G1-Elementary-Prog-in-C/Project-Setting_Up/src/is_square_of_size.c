/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** is_square_of_size
*/
#include "../include/my.h"
#include "../include/call.h"
// * Write a function that returns 1 if a square of a given size can
// * be found in the position indicated as parameter (row, col),
// * and 0 otherwise.

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < square_size; i++) {
        for (j = 0; j < square_size; j++) {
            return map[row + i][col + j] != '.' ? 0 : 1;
        }
    }
    return 1;
}
