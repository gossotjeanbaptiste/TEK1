/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_get_value function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"

static int find_column_index(dataframe_t *dataframe, const char *column_name)
{
    if (!dataframe || !column_name)
        return -1;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->columns[i].name, column_name) == 0)
            return i;
    }
    return -1;
}

void *df_get_value(dataframe_t *dataframe, int row, const char *column)
{
    int col_idx;

    if (!dataframe || row < 0 || row >= dataframe->nb_rows || !column)
        return NULL;
    col_idx = find_column_index(dataframe, column);
    if (col_idx == -1)
        return NULL;
    return dataframe->columns[col_idx].values[row];
}
