/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Dataframe utility functions for the Cuddle library (part 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/utils.h"

static char **extract_column_values(char ***data, int column_idx,
    int nb_lines)
{
    char **column_values = malloc(sizeof(char *) * (nb_lines - 1));

    if (!column_values)
        return NULL;
    for (int j = 0; j < nb_lines - 1; j++)
        column_values[j] = (data[j][column_idx]) ?
            strdup(data[j][column_idx]) : NULL;
    return column_values;
}

static void process_column_values_internal(dataframe_t *df,
    char **column_values, int column_idx, int nb_lines)
{
    df->columns[column_idx].type = detect_column_type(column_values,
        nb_lines - 1);
    for (int j = 0; j < nb_lines - 1; j++) {
        df->columns[column_idx].values[j] = convert_value(column_values[j],
            df->columns[column_idx].type);
        free(column_values[j]);
    }
}

void process_data(dataframe_t *df, char ***data, int nb_lines,
    int nb_columns)
{
    int i;
    char **column_values;

    for (i = 0; i < nb_columns; i++) {
        column_values = extract_column_values(data, i, nb_lines);
        if (!column_values)
            return;
        process_column_values_internal(df, column_values, i, nb_lines);
        free(column_values);
    }
}
