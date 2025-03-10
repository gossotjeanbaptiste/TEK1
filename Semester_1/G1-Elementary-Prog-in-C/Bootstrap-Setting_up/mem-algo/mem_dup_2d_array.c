/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** mem_dup_2d_array
*/
#include <stddef.h>
#include "../include/my.h"
#include "../include/call.h"

char **mem_dup_2d_array(int nb_rows, int nb_cols)
{
    char **new = malloc(sizeof(char *) * (nb_rows + 1));
    int i = 0;

    if (new == NULL)
        return (NULL);
    for (i = 0; i < nb_rows; i++) {
        new[i] = malloc(sizeof(char) * (nb_cols + 1));
        if (new[i] == NULL)
            return (NULL);
    }
    new[i] = NULL;
    return (new);
}
