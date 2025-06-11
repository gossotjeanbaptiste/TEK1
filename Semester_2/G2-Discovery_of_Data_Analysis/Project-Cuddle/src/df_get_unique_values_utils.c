/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_get_unique_values function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"

static bool compare_bool_values(void *value1, void *value2)
{
    return (*(bool *)value1 == *(bool *)value2);
}

static bool compare_int_values(void *value1, void *value2)
{
    return (*(int *)value1 == *(int *)value2);
}

static bool compare_uint_values(void *value1, void *value2)
{
    return (*(unsigned int *)value1 == *(unsigned int *)value2);
}

static bool compare_float_values(void *value1, void *value2)
{
    return (*(float *)value1 == *(float *)value2);
}

static bool compare_string_values(void *value1, void *value2)
{
    return (strcmp((char *)value1, (char *)value2) == 0);
}

bool values_are_equal(void *value1, void *value2, column_type_t type)
{
    switch (type) {
        case BOOL:
            return compare_bool_values(value1, value2);
        case INT:
            return compare_int_values(value1, value2);
        case UINT:
            return compare_uint_values(value1, value2);
        case FLOAT:
            return compare_float_values(value1, value2);
        case STRING:
            return compare_string_values(value1, value2);
        default:
            return false;
    }
}

bool is_value_unique_utils(void **values, int index, column_type_t type)
{
    int j = 0;

    for (j = 0; j < index; j++) {
        if (!values[j])
            continue;
        if (values_are_equal(values[index], values[j], type))
            return false;
    }
    return true;
}

int count_unique(void **values, int nb_rows, column_type_t type)
{
    int count = 0;
    int i = 0;
    bool is_unique = false;

    for (i = 0; i < nb_rows; i++) {
        if (!values[i])
            continue;
        is_unique = is_value_unique_utils(values, i, type);
        if (is_unique)
            count++;
    }
    return count;
}
