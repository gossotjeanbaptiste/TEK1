/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Filter utility functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/utils.h"

int count_filtered_rows(dataframe_t *df, int col_idx,
    bool (*filter_func)(void *))
{
    int count;
    int i;

    count = 0;
    for (i = 0; i < df->nb_rows; i++) {
        if (filter_func(df->columns[col_idx].values[i]))
            count++;
    }
    return count;
}

static void copy_value_if_matches(filter_copy_ctx_t ctx, int row_idx,
    int *curr_row, bool (*filter_func)(void *))
{
    if (filter_func(ctx.src->columns[ctx.col_idx].values[row_idx])) {
        ctx.filtered->columns[ctx.col_i].values[*curr_row] = copy_value(
            ctx.src->columns[ctx.col_i].values[row_idx],
            ctx.src->columns[ctx.col_i].type);
        (*curr_row)++;
    }
}

static void process_column_rows(filter_copy_ctx_t ctx,
    bool (*filter_func)(void *))
{
    int j;
    int curr_row;

    curr_row = 0;
    for (j = 0; j < ctx.src->nb_rows; j++) {
        copy_value_if_matches(ctx, j, &curr_row, filter_func);
    }
}

void copy_filtered_vals(dataframe_t *filtered, dataframe_t *src,
    int col_idx, bool (*filter_func)(void *))
{
    int i;
    filter_copy_ctx_t ctx;

    for (i = 0; i < filtered->nb_columns; i++) {
        if (!alloc_col_vals(filtered, i, filtered->nb_rows)) {
            df_free(filtered);
            return;
        }
        ctx.filtered = filtered;
        ctx.src = src;
        ctx.col_idx = col_idx;
        ctx.col_i = i;
        process_column_rows(ctx, filter_func);
    }
}

dataframe_t *create_filtered_df(dataframe_t *df, int col_idx,
    int filtered_rows, bool (*filter_func)(void *))
{
    dataframe_t *filtered;

    filtered = copy_df_struct(df);
    if (!filtered)
        return NULL;
    filtered->nb_rows = filtered_rows;
    copy_filtered_vals(filtered, df, col_idx, filter_func);
    return filtered;
}
