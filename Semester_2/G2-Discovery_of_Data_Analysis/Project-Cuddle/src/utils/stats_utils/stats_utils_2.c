/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Statistics utility functions (part 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

float calc_mean(void **values, int rows, column_type_t type)
{
    float sum;
    int count;
    int i;

    sum = 0.0;
    count = 0;
    for (i = 0; i < rows; i++) {
        if (!values[i] || !is_numeric_type(type))
            continue;
        sum += get_numeric_value(values[i], type);
        count++;
    }
    return (count > 0) ? sum / count : 0.0;
}

float calc_std(calc_std_ctx_t ctx)
{
    float sum_sq_diff;
    int count;
    float value;
    int i;

    sum_sq_diff = 0.0;
    count = 0;
    for (i = 0; i < ctx.rows; i++) {
        if (!ctx.values[i] || !is_numeric_type(ctx.type))
            continue;
        value = get_numeric_value(ctx.values[i], ctx.type);
        sum_sq_diff += (value - ctx.mean) * (value - ctx.mean);
        count++;
    }
    return (count > 0) ? sqrt(sum_sq_diff / count) : 0.0;
}

float get_min(void **values, int rows, column_type_t type)
{
    float min;
    bool initialized;
    float value;
    int i;

    min = 0.0;
    initialized = false;
    for (i = 0; i < rows; i++) {
        if (!values[i] || !is_numeric_type(type))
            continue;
        value = get_numeric_value(values[i], type);
        if (!initialized || value < min) {
            min = value;
            initialized = true;
        }
    }
    return min;
}

float get_max(void **values, int rows, column_type_t type)
{
    float max;
    bool initialized;
    float value;
    int i;

    max = 0.0;
    initialized = false;
    for (i = 0; i < rows; i++) {
        if (!values[i] || !is_numeric_type(type))
            continue;
        value = get_numeric_value(values[i], type);
        if (!initialized || value > max) {
            max = value;
            initialized = true;
        }
    }
    return max;
}
