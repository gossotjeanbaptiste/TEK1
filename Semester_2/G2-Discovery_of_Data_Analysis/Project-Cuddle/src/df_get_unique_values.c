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
#include "../include/utils.h"

static void *copy_bool_value(void *value)
{
    void *new_value = malloc(sizeof(bool));

    if (new_value)
        *(bool *)new_value = *(bool *)value;
    return new_value;
}

static void *copy_int_value(void *value)
{
    void *new_value = malloc(sizeof(int));

    if (new_value)
        *(int *)new_value = *(int *)value;
    return new_value;
}

static void *copy_uint_value(void *value)
{
    void *new_value = malloc(sizeof(unsigned int));

    if (new_value)
        *(unsigned int *)new_value = *(unsigned int *)value;
    return new_value;
}

static void *copy_float_value(void *value)
{
    void *new_value = malloc(sizeof(float));

    if (new_value)
        *(float *)new_value = *(float *)value;
    return new_value;
}

static void *copy_string_value(void *value)
{
    return strdup((char *)value);
}

static void *copy_value_unique(void *value, column_type_t type)
{
    if (!value)
        return NULL;
    switch (type) {
        case BOOL:
            return copy_bool_value(value);
        case INT:
            return copy_int_value(value);
        case UINT:
            return copy_uint_value(value);
        case FLOAT:
            return copy_float_value(value);
        case STRING:
        default:
            return copy_string_value(value);
    }
}

static void **allocate_unique_values(int unique_count)
{
    void **values = malloc(sizeof(void *) * (unique_count + 1));

    if (values)
        values[unique_count] = NULL;
    return values;
}

static bool is_column_value_unique(dataframe_t *df, int col_idx, int index)
{
    int j = 0;
    column_type_t type = df->columns[col_idx].type;
    void **values = df->columns[col_idx].values;

    for (j = 0; j < index; j++) {
        if (!values[j])
            continue;
        if (values_are_equal(values[index], values[j], type))
            return false;
    }
    return true;
}

static void **collect_unique_values(dataframe_t *df, int col_idx,
    int unique_count)
{
    void **values = allocate_unique_values(unique_count);
    int current = 0;
    int i = 0;
    bool is_unique = false;

    if (!values)
        return NULL;
    for (i = 0; i < df->nb_rows; i++) {
        if (!df->columns[col_idx].values[i])
            continue;
        is_unique = is_column_value_unique(df, col_idx, i);
        if (is_unique) {
            values[current] = copy_value_unique(df->columns[col_idx].values[i],
                df->columns[col_idx].type);
            current++;
        }
    }
    return values;
}

void **df_get_unique_values(dataframe_t *dataframe, const char *column)
{
    int col_idx = 0;
    int unique_count = 0;

    if (!dataframe || !column)
        return NULL;
    col_idx = find_column_index(dataframe, column);
    if (col_idx == -1)
        return NULL;
    unique_count = count_unique(dataframe->columns[col_idx].values,
        dataframe->nb_rows, dataframe->columns[col_idx].type);
    return collect_unique_values(dataframe, col_idx, unique_count);
}
