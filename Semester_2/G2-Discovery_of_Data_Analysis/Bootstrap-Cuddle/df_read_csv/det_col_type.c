/*
** EPITECH PROJECT, 2025
** Bootstrap-Cuddle
** File description:
** det_col_type
*/
#include "../include/dataframe.h"
#include "../include/my.h"
#include <fcntl.h>

static int is_int(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return 0;
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

static int is_uint(const char *str)
{
    if (!*str)
        return 0;
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

static int float_verif(const char *str)
{
    int has_dot = 0;

    if (*str == '.') {
        if (has_dot)
            return 0;
        has_dot = 1;
    } else {
        if (!isdigit(*str))
            return 0;
    }
    return 1;
}

static int is_float(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return 0;
    while (*str) {
        if (float_verif(str) == 0)
            return 0;
        str++;
    }
    return 1;
}

static int is_bool(const char *str)
{
    return (strcmp(str, "true") == 0 || strcmp(str, "false") == 0);
}

static void cond_col_typ(determine_t *det, dataframe_t *df, int col)
{
    det->is_int_col = 1;
    det->is_uint_col = 1;
    det->is_float_col = 1;
    det->is_bool_col = 1;
    for (int row = 0; row < df->nb_rows; row++) {
        det->value = (char *)df->data[row][col];
        if (!is_int(det->value))
            det->is_int_col = 0;
        if (!is_uint(det->value))
            det->is_uint_col = 0;
        if (!is_float(det->value))
            det->is_float_col = 0;
        if (!is_bool(det->value))
            det->is_bool_col = 0;
    }
}

void determine_column_types(dataframe_t *df)
{
    determine_t *det = malloc(sizeof(determine_t));

    df->column_types = malloc(df->nb_columns * sizeof(column_type_t));
    for (int col = 0; col < df->nb_columns; col++) {
        cond_col_typ(det, df, col);
        if (det->is_bool_col)
            df->column_types[col] = BOOL;
        if (det->is_int_col)
            df->column_types[col] = INT;
        if (det->is_uint_col)
            df->column_types[col] = UINT;
        if (det->is_float_col)
            df->column_types[col] = FLOAT;
        else
            df->column_types[col] = STRING;
    }
    free(det->value);
    free(det);
}
