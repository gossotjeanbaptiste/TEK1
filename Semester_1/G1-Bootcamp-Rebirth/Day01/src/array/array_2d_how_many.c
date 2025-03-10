/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** array_2d_how_many
*/

#include "../../include/my.h"

int comparaison(int pos_arr, int number_comp, int nb_pres)
{
    if (pos_arr == number_comp)
        nb_pres++;
    return nb_pres;
}

int array_2d_how_many(int const **arr, int nb_rows, int nb_cols, int number)
{
    int nb_pres = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            comparaison(arr[i][j], number, nb_pres);
        }
    }
    return nb_pres;
}
