/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_describe function (part 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../../include/dataframe.h"

static float sum_squared_differences(sum_squared_ctx_t ctx)
{
    float sum_squared_diff = 0.0;
    float value;

    *(ctx.count) = 0;
    for (int i = 0; i < ctx.nb_rows; i++) {
        if (!ctx.values[i] || !is_numeric_type(ctx.type))
            continue;
        value = get_numeric_value(ctx.values[i], ctx.type);
        sum_squared_diff += (value - ctx.mean) * (value - ctx.mean);
        (*(ctx.count))++;
    }
    return sum_squared_diff;
}

float calc_std(calc_std_ctx_t ctx)
{
    int count = 0;
    float sum_squared;
    sum_squared_ctx_t sum_ctx;

    sum_ctx.values = ctx.values;
    sum_ctx.nb_rows = ctx.rows;
    sum_ctx.type = ctx.type;
    sum_ctx.mean = ctx.mean;
    sum_ctx.count = &count;
    sum_squared = sum_squared_differences(sum_ctx);
    return (count > 0) ? sqrt(sum_squared / count) : 0.0;
}
