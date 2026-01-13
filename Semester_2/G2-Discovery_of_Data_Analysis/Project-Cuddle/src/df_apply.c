/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_apply function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"
#include "../include/utils.h"

dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *))
{
    dataframe_t *result = NULL;
    int col_idx = 0;

    if (!dataframe || !column || !apply_func)
        return NULL;
    col_idx = find_column_index(dataframe, column);
    if (col_idx == -1)
        return NULL;
    result = create_apply_result_dataframe(dataframe);
    if (!result)
        return NULL;
    if (!copy_applied_values(result, dataframe, col_idx, apply_func)) {
        df_free(result);
        return NULL;
    }
    return result;
}
