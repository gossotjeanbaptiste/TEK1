/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_to_type function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/dataframe.h"
#include "../../include/utils.h"

static void *convert_to_bool(const char *value)
{
    void *result = malloc(sizeof(bool));

    if (result)
        *(bool *)result = (strcasecmp(value, "true") == 0);
    return result;
}

static void *convert_to_int(const char *value)
{
    void *result = malloc(sizeof(int));

    if (result)
        *(int *)result = atoi(value);
    return result;
}

static void *convert_to_uint(const char *value)
{
    void *result = malloc(sizeof(unsigned int));

    if (result)
        *(unsigned int *)result = (unsigned int)strtoul(value, NULL, 10);
    return result;
}

static void *convert_to_float(const char *value)
{
    void *result = malloc(sizeof(float));

    if (result)
        *(float *)result = atof(value);
    return result;
}

static void *convert_value_to_type(const char *value, column_type_t type)
{
    if (!value)
        return NULL;
    switch (type) {
        case BOOL:
            return convert_to_bool(value);
        case INT:
            return convert_to_int(value);
        case UINT:
            return convert_to_uint(value);
        case FLOAT:
            return convert_to_float(value);
        case STRING:
        default:
            return strdup(value);
    }
}

static bool check_conversion_possible(dataframe_t *df, int col_idx,
    column_type_t type)
{
    int i = 0;

    for (i = 0; i < df->nb_rows; i++) {
        if (!can_convert_to_type((char *)df->columns[col_idx].values[i], type))
            return false;
    }
    return true;
}

static bool allocate_column_values_internal(dataframe_t *df, int i, int rows)
{
    df->columns[i].values = malloc(sizeof(void *) * rows);
    return (df->columns[i].values != NULL);
}

static void *get_converted_value(void *src_value, column_type_t src_type,
    column_type_t target_type, int is_target_column)
{
    if (is_target_column) {
        return convert_value_to_type((char *)src_value, target_type);
    } else {
        return copy_value_type(src_value, src_type);
    }
}

static void copy_converted_values(dataframe_t *result, dataframe_t *src,
    int col_idx, column_type_t type)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < result->nb_columns; i++) {
        if (!allocate_column_values_internal(result, i, result->nb_rows)) {
            df_free(result);
            return;
        }
        for (j = 0; j < result->nb_rows; j++) {
            result->columns[i].values[j] = get_converted_value(
                src->columns[i].values[j],
                src->columns[i].type,
                (i == col_idx) ? type : src->columns[i].type,
                (i == col_idx)
            );
        }
    }
}

dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast)
{
    dataframe_t *result;
    int col_idx;

    if (!dataframe || !column)
        return NULL;
    col_idx = find_column_idx_internal(dataframe, column);
    if (col_idx == -1)
        return NULL;
    if (!check_conversion_possible(dataframe, col_idx, downcast))
        return NULL;
    result = copy_dataframe_structure(dataframe);
    if (!result)
        return NULL;
    result->nb_rows = dataframe->nb_rows;
    result->columns[col_idx].type = downcast;
    copy_converted_values(result, dataframe, col_idx, downcast);
    return result;
}
