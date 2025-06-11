/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_sort function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"
#include "../include/utils.h"

static dataframe_t *create_sorted_dataframe(dataframe_t *dataframe,
    sort_context_t *ctx)
{
    dataframe_t *sorted = copy_df_struct(dataframe);

    if (!sorted)
        return NULL;
    sorted->nb_rows = dataframe->nb_rows;
    sort_indices(ctx);
    copy_sorted_vals(sorted, dataframe, ctx->indices);
    free(ctx->indices);
    return sorted;
}

dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_func)(void *value1, void *value2))
{
    dataframe_t *sorted;
    int col_idx;
    sort_context_t ctx;

    if (!dataframe || !column || !sort_func)
        return NULL;
    col_idx = find_col_idx(dataframe, column);
    if (col_idx == -1)
        return NULL;
    ctx.sort_func = sort_func;
    if (!init_sort_ctx(&ctx, dataframe, col_idx))
        return NULL;
    sorted = create_sorted_dataframe(dataframe, &ctx);
    if (!sorted)
        return NULL;
    return sorted;
}
