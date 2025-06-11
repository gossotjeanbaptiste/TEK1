/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_describe function (part 3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include "../../include/dataframe.h"

static float find_first_valid_value(void **values, int nb_rows,
    column_type_t type, bool *found)
{
    float value = 0.0;

    *found = false;
    for (int i = 0; i < nb_rows && !(*found); i++) {
        if (!values[i] || !is_numeric_type(type))
            continue;
        value = get_numeric_value(values[i], type);
        *found = true;
    }
    return value;
}

float get_min(void **values, int rows, column_type_t type)
{
    bool found = false;
    float min = find_first_valid_value(values, rows, type, &found);
    float value;

    if (!found)
        return 0.0;
    for (int i = 0; i < rows; i++) {
        if (!values[i] || !is_numeric_type(type))
            continue;
        value = get_numeric_value(values[i], type);
        if (value < min) {
            min = value;
        }
    }
    return min;
}
