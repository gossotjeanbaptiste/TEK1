/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_describe function (part 1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../../include/dataframe.h"

bool is_numeric_type(column_type_t type)
{
    return (type == INT || type == UINT || type == FLOAT);
}

float get_numeric_value(void *value, column_type_t type)
{
    if (!value)
        return 0.0;
    switch (type) {
        case INT:
            return *(int *)value;
        case UINT:
            return *(unsigned int *)value;
        case FLOAT:
            return *(float *)value;
        default:
            return 0.0;
    }
}

static float sum_values(void **values, int nb_rows,
    column_type_t type, int *count)
{
    float sum = 0.0;

    *count = 0;
    if (!is_numeric_type(type))
        return 0.0;
    for (int i = 0; i < nb_rows; i++) {
        if (!values[i])
            continue;
        sum += get_numeric_value(values[i], type);
        (*count)++;
    }
    return sum;
}

float calc_mean(void **values, int rows, column_type_t type)
{
    int count = 0;
    float sum = sum_values(values, rows, type, &count);

    return (count > 0) ? sum / count : 0.0;
}
