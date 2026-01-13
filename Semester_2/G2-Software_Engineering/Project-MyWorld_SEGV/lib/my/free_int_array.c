/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** free_int_array
*/
#include "my.h"

void free_int_array(int **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
