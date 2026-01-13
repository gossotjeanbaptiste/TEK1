/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Apply utility functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/utils.h"

bool allocate_column_values(dataframe_t *df, int i, int rows)
{
    df->columns[i].values = malloc(sizeof(void *) * rows);
    return (df->columns[i].values != NULL);
}

void *process_value(void *value, bool should_apply,
    void *(*apply_func)(void *), column_type_t type)
{
    if (should_apply)
        return apply_func(value);
    return copy_value(value, type);
}

void process_column_values(process_column_values_ctx_t ctx)
{
    int j = 0;
    bool should_apply = (ctx.i == ctx.col_idx);

    for (j = 0; j < ctx.result->nb_rows; j++) {
        ctx.result->columns[ctx.i].values[j] = process_value(
            ctx.src->columns[ctx.i].values[j], should_apply,
            ctx.apply_func, ctx.src->columns[ctx.i].type);
    }
}

bool copy_applied_values(dataframe_t *result, dataframe_t *src,
    int col_idx, void *(*apply_func)(void *))
{
    int i = 0;
    process_column_values_ctx_t ctx;

    if (!allocate_all_column_values(result))
        return false;
    ctx.result = result;
    ctx.src = src;
    ctx.col_idx = col_idx;
    ctx.apply_func = apply_func;
    for (i = 0; i < result->nb_columns; i++) {
        ctx.i = i;
        process_column_values(ctx);
    }
    return true;
}

dataframe_t *create_apply_result_dataframe(dataframe_t *dataframe)
{
    dataframe_t *result = copy_df_struct(dataframe);

    if (result)
        result->nb_rows = dataframe->nb_rows;
    return result;
}
