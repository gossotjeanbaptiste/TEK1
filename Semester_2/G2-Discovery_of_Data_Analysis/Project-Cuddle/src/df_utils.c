/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_read_csv function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/dataframe.h"

void free_tokens(char **tokens)
{
    if (!tokens)
        return;
    for (int i = 0; tokens[i]; i++)
        free(tokens[i]);
    free(tokens);
}

int find_column_idx_internal(dataframe_t *dataframe, const char *column_name)
{
    int i = 0;

    if (!dataframe || !column_name)
        return -1;
    for (i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->columns[i].name, column_name) == 0)
            return i;
    }
    return -1;
}
