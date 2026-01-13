/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Value utility functions for the Cuddle library
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/utils.h"

static void *copy_bool_val(void *value)
{
    void *new_val;

    new_val = malloc(sizeof(bool));
    if (new_val)
        *(bool *)new_val = *(bool *)value;
    return new_val;
}

static void *copy_int_val(void *value)
{
    void *new_val;

    new_val = malloc(sizeof(int));
    if (new_val)
        *(int *)new_val = *(int *)value;
    return new_val;
}

static void *copy_uint_val(void *value)
{
    void *new_val;

    new_val = malloc(sizeof(unsigned int));
    if (new_val)
        *(unsigned int *)new_val = *(unsigned int *)value;
    return new_val;
}

static void *copy_float_val(void *value)
{
    void *new_val;

    new_val = malloc(sizeof(float));
    if (new_val)
        *(float *)new_val = *(float *)value;
    return new_val;
}

static void *copy_string_val(void *value)
{
    return strdup((char *)value);
}

void *copy_value(void *value, column_type_t type)
{
    if (!value)
        return NULL;
    switch (type) {
    case BOOL:
        return copy_bool_val(value);
    case INT:
        return copy_int_val(value);
    case UINT:
        return copy_uint_val(value);
    case FLOAT:
        return copy_float_val(value);
    case STRING:
    default:
        return copy_string_val(value);
    }
}
