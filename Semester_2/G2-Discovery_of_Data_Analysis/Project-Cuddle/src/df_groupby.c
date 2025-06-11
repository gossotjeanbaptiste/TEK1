/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_groupby function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"
#include "../include/utils.h"

static bool validate_groupby_params(groupby_ctx_t *ctx)
{
    return (ctx->dataframe && ctx->aggregate_by &&
            ctx->to_aggregate && ctx->agg_func);
}

static bool find_groupby_columns(groupby_ctx_t *ctx)
{
    ctx->col_idx = find_column_index(ctx->dataframe, ctx->aggregate_by);
    ctx->agg_col_idx = find_column_index(ctx->dataframe, ctx->to_aggregate[0]);
    return (ctx->col_idx != -1 && ctx->agg_col_idx != -1);
}

static dataframe_t *create_result(groupby_ctx_t *ctx)
{
    dataframe_t *result = create_result_dataframe(ctx->unique_count);

    if (!result)
        return NULL;
    return result;
}

static bool init_columns(dataframe_t *result, groupby_ctx_t *ctx)
{
    if (!init_result_columns(result, ctx->aggregate_by, ctx->to_aggregate[0],
        ctx->dataframe->columns[ctx->agg_col_idx].type)) {
        df_free(result);
        return false;
    }
    return true;
}

static dataframe_t *init_groupby_result(groupby_ctx_t *ctx)
{
    dataframe_t *result = create_result(ctx);

    if (!result)
        return NULL;
    if (!init_columns(result, ctx))
        return NULL;
    return result;
}

static bool process_groupby_data(dataframe_t *result, groupby_ctx_t *ctx)
{
    int unique_count = 0;
    char **unique_values = get_unique_values(ctx->dataframe,
                                            ctx->col_idx, &unique_count);
    process_all_groups_ctx_t pg_ctx;

    if (!unique_values) {
        df_free(result);
        return false;
    }
    pg_ctx.result = result;
    pg_ctx.dataframe = ctx->dataframe;
    pg_ctx.col_idx = ctx->col_idx;
    pg_ctx.agg_col_idx = ctx->agg_col_idx;
    pg_ctx.unique_values = unique_values;
    pg_ctx.unique_count = unique_count;
    pg_ctx.agg_func = ctx->agg_func;
    if (!process_all_groups(pg_ctx))
        return false;
    free_unique_values(unique_values, unique_count);
    return true;
}

static bool setup_groupby_context(groupby_ctx_t *ctx)
{
    if (!validate_groupby_params(ctx) || !find_groupby_columns(ctx))
        return false;
    ctx->unique_count = count_unique_values(ctx->dataframe, ctx->col_idx);
    return (ctx->unique_count > 0);
}

dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate, void *(*agg_func)(void **, int))
{
    groupby_ctx_t ctx;
    dataframe_t *result = NULL;

    ctx.dataframe = dataframe;
    ctx.aggregate_by = aggregate_by;
    ctx.to_aggregate = to_aggregate;
    ctx.agg_func = agg_func;
    ctx.col_idx = 0;
    ctx.agg_col_idx = 0;
    ctx.unique_count = 0;
    if (!setup_groupby_context(&ctx))
        return NULL;
    result = init_groupby_result(&ctx);
    if (!result ||
        !process_groupby_data(result, &ctx))
        return NULL;
    return result;
}
