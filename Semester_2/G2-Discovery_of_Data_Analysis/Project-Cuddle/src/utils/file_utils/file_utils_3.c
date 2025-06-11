/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** File utility functions for the Cuddle library (part 3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

void write_float_value(FILE *file, void *value)
{
    if (!value)
        return;
    fprintf(file, "%.2f", *(float *)value);
}

void write_string_value(FILE *file, void *value)
{
    if (!value)
        return;
    fprintf(file, "%s", (char *)value);
}

void write_value(FILE *file, void *value, column_type_t type)
{
    static void (*writers[])(FILE *, void *) = {
        [BOOL] = write_bool_value,
        [INT] = write_int_value,
        [UINT] = write_uint_value,
        [FLOAT] = write_float_value,
        [STRING] = write_string_value
    };

    if (!value)
        return;
    if (type < sizeof(writers) / sizeof(writers[0]) && writers[type])
        writers[type](file, value);
    else
        write_string_value(file, value);
}
