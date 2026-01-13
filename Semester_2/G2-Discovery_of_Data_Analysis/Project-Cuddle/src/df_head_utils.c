/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_head function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"

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

void *copy_value_head(void *value, column_type_t type)
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
