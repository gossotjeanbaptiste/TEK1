/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** array_2d_how_many
*/
#include "../include/my.h"
#include "../include/call.h"

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
    int nb_presence = 0;

    for (int x = 0; x < nb_rows; x++) {
        for (int y = 0; y < nb_cols; y++) {
            nb_presence += annexe_array_2d_how_many(arr, x, y, number);
        }
    }
    return nb_presence;
}

int annexe_array_2d_how_many(int **arr, int x, int y, int number)
{
    int nb_presence = 0;

    if (arr[x][y] == number) {
        nb_presence++;
    }
    return nb_presence;
}
