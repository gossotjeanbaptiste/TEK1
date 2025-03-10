/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** array_2d_sum
*/
#include "../include/my.h"
#include "../include/call.h"


int array_2d_sum(int **arr, int nb_rows, int nb_cols)
{
    int sum = 0;

    for (int x = 0; x < nb_rows; x++) {
        for (int y = 0; y < nb_cols; y++) {
            sum += arr[x][y];
        }
    }
    return sum;
}
