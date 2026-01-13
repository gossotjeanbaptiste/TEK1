/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Statistics utility functions (part 1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

static float get_int_value(void *value)
{
    return (float)(*(int *)value);
}

static float get_uint_value(void *value)
{
    return (float)(*(unsigned int *)value);
}

static float get_float_value(void *value)
{
    return *(float *)value;
}

float get_numeric_value(void *value, column_type_t type)
{
    switch (type) {
    case INT:
        return get_int_value(value);
    case UINT:
        return get_uint_value(value);
    case FLOAT:
        return get_float_value(value);
    default:
        return 0.0;
    }
}

bool is_numeric_type(column_type_t type)
{
    return (type == INT || type == UINT || type == FLOAT);
}
