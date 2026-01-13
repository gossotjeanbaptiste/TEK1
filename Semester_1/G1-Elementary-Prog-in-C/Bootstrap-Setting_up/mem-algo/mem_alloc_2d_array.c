/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** mem_alloc_2d_array
*/
#include "../include/call.h"
#include "../include/my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **array = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i < nb_rows; i++) {
        array[i] = malloc(sizeof(char) * nb_cols);
    }
    return array;
}
