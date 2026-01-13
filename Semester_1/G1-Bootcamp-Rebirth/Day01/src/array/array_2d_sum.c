/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** array_2d_sum
*/

#include "../../include/my.h"

int array_2d_sum(int const **arr, int nb_rows, int nb_cols)
{
    int sum = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}
