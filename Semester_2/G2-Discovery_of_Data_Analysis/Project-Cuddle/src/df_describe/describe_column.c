/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_describe function (part 6)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../../include/dataframe.h"

static void calculate_column_stats(calculate_stats_ctx_t ctx)
{
    calc_std_ctx_t std_ctx;

    *(ctx.mean) = calc_mean(ctx.column.values, ctx.nb_rows, ctx.column.type);
    std_ctx.values = ctx.column.values;
    std_ctx.rows = ctx.nb_rows;
    std_ctx.type = ctx.column.type;
    std_ctx.mean = *(ctx.mean);
    *(ctx.std) = calc_std(std_ctx);
    *(ctx.min) = get_min(ctx.column.values, ctx.nb_rows, ctx.column.type);
    *(ctx.max) = get_max(ctx.column.values, ctx.nb_rows, ctx.column.type);
}

static void populate_stats(dataframe_t *df, int col_idx,
    column_stats_info_t *stats)
{
    float mean;
    float std;
    float min;
    float max;
    column_t column = df->columns[col_idx];
    calculate_stats_ctx_t calc_ctx;

    calc_ctx.column = column;
    calc_ctx.nb_rows = df->nb_rows;
    calc_ctx.mean = &mean;
    calc_ctx.std = &std;
    calc_ctx.min = &min;
    calc_ctx.max = &max;
    calculate_column_stats(calc_ctx);
    stats->name = column.name;
    stats->count = df->nb_rows;
    stats->mean = mean;
    stats->std = std;
    stats->min = min;
    stats->max = max;
}

void describe_column(dataframe_t *df, int col_idx)
{
    column_stats_info_t stats;
    column_t column = df->columns[col_idx];

    if (!is_numeric_type(column.type))
        return;
    populate_stats(df, col_idx, &stats);
    print_col_stats(stats);
}
