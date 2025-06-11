/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Sort utility functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/utils.h"

static void swap_indices(int *indices, int i, int j)
{
    int temp;

    temp = indices[i];
    indices[i] = indices[j];
    indices[j] = temp;
}

static void bubble_sort_step(sort_context_t *ctx, int j)
{
    if (ctx->sort_func(ctx->values[ctx->indices[j]],
            ctx->values[ctx->indices[j + 1]]))
        swap_indices(ctx->indices, j, j + 1);
}

void sort_indices(sort_context_t *ctx)
{
    int i;
    int j;

    for (i = 0; i < ctx->size - 1; i++) {
        for (j = 0; j < ctx->size - i - 1; j++) {
            bubble_sort_step(ctx, j);
        }
    }
}

bool init_sort_ctx(sort_context_t *ctx, dataframe_t *df, int col_idx)
{
    int i;

    ctx->values = df->columns[col_idx].values;
    ctx->indices = malloc(sizeof(int) * df->nb_rows);
    if (!ctx->indices)
        return false;
    ctx->size = df->nb_rows;
    for (i = 0; i < df->nb_rows; i++)
        ctx->indices[i] = i;
    return true;
}

void copy_sorted_vals(dataframe_t *sorted, dataframe_t *src, int *indices)
{
    int i;
    int j;

    for (i = 0; i < sorted->nb_columns; i++) {
        if (!alloc_col_vals(sorted, i, sorted->nb_rows))
            return;
        for (j = 0; j < sorted->nb_rows; j++) {
            sorted->columns[i].values[j] = copy_value(
                src->columns[i].values[indices[j]],
                src->columns[i].type);
        }
    }
}
