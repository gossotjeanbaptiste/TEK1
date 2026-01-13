/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Type utility functions for the Cuddle library
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

static bool check_numeric_types(check_numeric_ctx_t ctx)
{
    for (int i = 0; i < ctx.nb_rows; i++) {
        if (!ctx.values[i])
            continue;
        if (!is_numeric(ctx.values[i]) && !is_float(ctx.values[i])) {
            *(ctx.all_int) = false;
            *(ctx.all_float) = false;
            continue;
        }
        if (strchr(ctx.values[i], '.') != NULL) {
            *(ctx.all_int) = false;
            continue;
        }
        if (ctx.values[i][0] == '-')
            *(ctx.has_negative) = true;
    }
    return true;
}

static bool check_bool_type(check_bool_ctx_t ctx)
{
    for (int i = 0; i < ctx.nb_rows; i++) {
        if (!ctx.values[i])
            continue;
        if (!is_bool(ctx.values[i]))
            *(ctx.all_bool) = false;
    }
    return true;
}

static column_type_t determine_type_from_flags(bool all_bool, bool all_float,
    bool all_int, bool has_negative)
{
    if (all_bool)
        return BOOL;
    if (all_int) {
        if (has_negative)
            return INT;
        return UINT;
    }
    if (all_float)
        return FLOAT;
    return STRING;
}

static void initialize_type_flags(bool *has_negative, bool *all_int,
    bool *all_float, bool *all_bool)
{
    *has_negative = false;
    *all_int = true;
    *all_float = true;
    *all_bool = true;
}

column_type_t detect_column_type(char **values, int nb_rows)
{
    bool has_negative;
    bool all_int;
    bool all_float;
    bool all_bool;
    check_numeric_ctx_t numeric_ctx;
    check_bool_ctx_t bool_ctx;

    initialize_type_flags(&has_negative, &all_int, &all_float, &all_bool);
    numeric_ctx = (check_numeric_ctx_t){values, nb_rows, &has_negative,
                                        &all_int, &all_float};
    bool_ctx = (check_bool_ctx_t){values, nb_rows, &all_bool};
    check_numeric_types(numeric_ctx);
    check_bool_type(bool_ctx);
    return determine_type_from_flags(all_bool, all_float,
        all_int, has_negative);
}
