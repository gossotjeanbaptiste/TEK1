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

void *copy_value_type(void *value, column_type_t type)
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

static bool allocate_column_name(dataframe_t *df, int i, dataframe_t *src)
{
    df->columns[i].name = strdup(src->columns[i].name);
    df->columns[i].type = src->columns[i].type;
    return (df->columns[i].name != NULL);
}

static void free_column_names(dataframe_t *df, int count)
{
    int j = 0;

    for (j = 0; j < count; j++)
        free(df->columns[j].name);
}

dataframe_t *copy_dataframe_structure(dataframe_t *dataframe)
{
    dataframe_t *new_df = malloc(sizeof(dataframe_t));
    int i = 0;

    if (!new_df)
        return NULL;
    new_df->nb_columns = dataframe->nb_columns;
    new_df->columns = malloc(sizeof(column_t) * new_df->nb_columns);
    if (!new_df->columns) {
        free(new_df);
        return NULL;
    }
    for (i = 0; i < new_df->nb_columns; i++) {
        if (!allocate_column_name(new_df, i, dataframe)) {
            free_column_names(new_df, i);
            free(new_df->columns);
            free(new_df);
            return NULL;
        }
    }
    return new_df;
}
