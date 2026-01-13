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

static bool check_bool_conversion(const char *value)
{
    return (strcasecmp(value, "true") == 0 ||
        strcasecmp(value, "false") == 0);
}

static bool check_int_conversion(const char *value)
{
    int i = 0;

    for (i = 0; value[i]; i++) {
        if (i == 0 && value[i] == '-')
            continue;
        if (value[i] < '0' || value[i] > '9')
            return false;
    }
    return true;
}

static bool check_uint_conversion(const char *value)
{
    int i = 0;

    for (i = 0; value[i]; i++) {
        if (value[i] < '0' || value[i] > '9')
            return false;
    }
    return true;
}

bool can_convert_to_type(const char *value, column_type_t type)
{
    if (!value)
        return false;
    switch (type) {
        case BOOL:
            return check_bool_conversion(value);
        case INT:
            return check_int_conversion(value);
        case UINT:
            return check_uint_conversion(value);
        case FLOAT:
        case STRING:
            return true;
        default:
            return false;
    }
}
