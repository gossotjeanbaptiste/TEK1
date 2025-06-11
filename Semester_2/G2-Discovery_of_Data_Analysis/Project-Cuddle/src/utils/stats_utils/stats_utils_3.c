/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Statistics utility functions (part 3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

static void print_col_name(const char *name)
{
    printf("Column: %s\n", name);
}

static void print_count(int count)
{
    printf("Count: %d\n", count);
}

static void print_stats(double mean, double std, double min, double max)
{
    printf("Mean: %.2f\n", mean);
    printf("Std: %.2f\n", std);
    printf("Min: %.2f\n", min);
    printf("Max: %.2f\n", max);
}

void print_col_stats(column_stats_info_t stats)
{
    print_col_name(stats.name);
    print_count(stats.count);
    print_stats(stats.mean, stats.std, stats.min, stats.max);
}

column_stats_t calc_col_stats(void **values, int rows, column_type_t type)
{
    column_stats_t stats;
    calc_std_ctx_t std_ctx;

    stats.mean = calc_mean(values, rows, type);
    std_ctx.values = values;
    std_ctx.rows = rows;
    std_ctx.type = type;
    std_ctx.mean = stats.mean;
    stats.std = calc_std(std_ctx);
    stats.min = get_min(values, rows, type);
    stats.max = get_max(values, rows, type);
    return stats;
}

void describe_column(dataframe_t *df, int col_idx)
{
    column_t column;
    column_stats_t stats;
    column_stats_info_t stats_info;

    column = df->columns[col_idx];
    if (!is_numeric_type(column.type))
        return;
    stats = calc_col_stats(column.values, df->nb_rows, column.type);
    stats_info.name = column.name;
    stats_info.count = df->nb_rows;
    stats_info.mean = stats.mean;
    stats_info.std = stats.std;
    stats_info.min = stats.min;
    stats_info.max = stats.max;
    print_col_stats(stats_info);
}

void describe_all_columns(dataframe_t *df)
{
    int i;

    for (i = 0; i < df->nb_columns; i++) {
        describe_column(df, i);
    }
}
