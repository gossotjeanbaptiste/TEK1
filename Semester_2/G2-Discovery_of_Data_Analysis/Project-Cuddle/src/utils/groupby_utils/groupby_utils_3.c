/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Groupby utility functions (part 3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

static void free_column_values(dataframe_t *result, int processed_rows)
{
    int j = 0;

    for (j = 0; j < processed_rows; j++) {
        free(result->columns[0].values[j]);
        free(result->columns[1].values[j]);
    }
}

void free_partial_result(partial_result_ctx_t ctx)
{
    free_column_values(ctx.result, ctx.processed_rows);
    free_unique_values(ctx.unique_values, ctx.unique_count);
    df_free(ctx.result);
}

static bool set_group_value(dataframe_t *result, int i, const char *value)
{
    result->columns[0].values[i] = strdup(value);
    return (result->columns[0].values[i] != NULL);
}

static bool apply_aggregation(apply_aggregation_ctx_t ctx)
{
    ctx.result->columns[1].values[ctx.i] = ctx.agg_func(ctx.values, ctx.count);
    return true;
}

static bool setup_and_collect_values(process_group_ctx_t *ctx,
    void ***values, int *count)
{
    collect_values_ctx_t collect_ctx;

    collect_ctx.dataframe = ctx->dataframe;
    collect_ctx.col_idx = ctx->col_idx;
    collect_ctx.agg_col_idx = ctx->agg_col_idx;
    collect_ctx.group_value = ctx->unique_values[ctx->i];
    collect_ctx.count = count;
    *values = collect_values_for_group(collect_ctx);
    if (!*values) {
        free(ctx->result->columns[0].values[ctx->i]);
        return false;
    }
    return true;
}

static bool collect_and_aggregate(process_group_ctx_t *ctx)
{
    int count = 0;
    void **values = NULL;
    apply_aggregation_ctx_t agg_ctx;

    if (!setup_and_collect_values(ctx, &values, &count))
        return false;
    agg_ctx.result = ctx->result;
    agg_ctx.values = values;
    agg_ctx.count = count;
    agg_ctx.i = ctx->i;
    agg_ctx.agg_func = ctx->agg_func;
    apply_aggregation(agg_ctx);
    free(values);
    return true;
}

bool process_group(process_group_ctx_t ctx)
{
    process_group_ctx_t internal_ctx;

    internal_ctx.result = ctx.result;
    internal_ctx.dataframe = ctx.dataframe;
    internal_ctx.col_idx = ctx.col_idx;
    internal_ctx.agg_col_idx = ctx.agg_col_idx;
    internal_ctx.unique_values = ctx.unique_values;
    internal_ctx.i = ctx.i;
    internal_ctx.agg_func = ctx.agg_func;
    if (!set_group_value(ctx.result, ctx.i, ctx.unique_values[ctx.i]))
        return false;
    return collect_and_aggregate(&internal_ctx);
}

static bool process_single_group(group_process_ctx_t *ctx, int i)
{
    process_group_ctx_t pg_ctx;

    pg_ctx.result = ctx->result;
    pg_ctx.dataframe = ctx->dataframe;
    pg_ctx.col_idx = ctx->col_idx;
    pg_ctx.agg_col_idx = ctx->agg_col_idx;
    pg_ctx.unique_values = ctx->unique_values;
    pg_ctx.i = i;
    pg_ctx.agg_func = ctx->agg_func;
    return process_group(pg_ctx);
}

static bool handle_group_failure(process_all_groups_ctx_t ctx,
    int processed_rows)
{
    partial_result_ctx_t pr_ctx;

    pr_ctx.result = ctx.result;
    pr_ctx.processed_rows = processed_rows;
    pr_ctx.unique_values = ctx.unique_values;
    pr_ctx.unique_count = ctx.unique_count;
    free_partial_result(pr_ctx);
    return false;
}

bool process_all_groups(process_all_groups_ctx_t ctx)
{
    group_process_ctx_t process_ctx;
    int i = 0;

    process_ctx.result = ctx.result;
    process_ctx.dataframe = ctx.dataframe;
    process_ctx.col_idx = ctx.col_idx;
    process_ctx.agg_col_idx = ctx.agg_col_idx;
    process_ctx.unique_values = ctx.unique_values;
    process_ctx.unique_count = ctx.unique_count;
    process_ctx.agg_func = ctx.agg_func;
    for (i = 0; i < ctx.unique_count; i++) {
        if (!process_single_group(&process_ctx, i))
            return handle_group_failure(ctx, i);
    }
    return true;
}
