/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_filter function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"
#include "../include/utils.h"

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value))
{
    int col_idx;
    int filtered_rows;

    if (!dataframe || !column || !filter_func)
        return NULL;
    col_idx = find_col_idx(dataframe, column);
    if (col_idx == -1)
        return NULL;
    filtered_rows = count_filtered_rows(dataframe, col_idx, filter_func);
    if (filtered_rows == 0)
        return NULL;
    return create_filtered_df(dataframe, col_idx, filtered_rows, filter_func);
}
