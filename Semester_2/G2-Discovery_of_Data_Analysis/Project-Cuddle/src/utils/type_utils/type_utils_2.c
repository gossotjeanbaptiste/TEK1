/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Type utility functions for the Cuddle library (part 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

static void *convert_bool(const char *value)
{
    bool *bool_value = malloc(sizeof(bool));

    if (!bool_value)
        return NULL;
    if (strcmp(value, "true") == 0 || strcmp(value, "1") == 0)
        *bool_value = true;
    else
        *bool_value = false;
    return bool_value;
}

static void *convert_int(const char *value)
{
    int *result = malloc(sizeof(int));

    if (!result)
        return NULL;
    *result = atoi(value);
    return result;
}

static void *convert_uint(const char *value)
{
    unsigned int *result = malloc(sizeof(unsigned int));

    if (!result)
        return NULL;
    *result = (unsigned int)atoi(value);
    return result;
}

static void *convert_float(const char *value)
{
    float *result = malloc(sizeof(float));
    char *endptr = NULL;
    float parsed_value = 0.0f;

    if (!result)
        return NULL;
    parsed_value = strtof(value, &endptr);
    if (endptr == value) {
        free(result);
        return NULL;
    }
    *result = parsed_value;
    return result;
}

void *convert_value(const char *value, column_type_t type)
{
    if (!value)
        return NULL;
    switch (type) {
        case BOOL:
            return convert_bool(value);
        case INT:
            return convert_int(value);
        case UINT:
            return convert_uint(value);
        case FLOAT:
            return convert_float(value);
        case STRING:
            return strdup(value);
        default:
            return strdup(value);
    }
}
