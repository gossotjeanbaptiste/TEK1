/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Dataframe utility functions for the Cuddle library
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/utils.h"

static bool alloc_col_values(dataframe_t *df, int rows)
{
    int i;
    int j;

    for (i = 0; i < df->nb_columns; i++) {
        df->columns[i].values = malloc(sizeof(void *) * rows);
        if (!df->columns[i].values)
            return false;
        for (j = 0; j < rows; j++)
            df->columns[i].values[j] = NULL;
    }
    return true;
}

static void init_columns(dataframe_t *df)
{
    int i;

    for (i = 0; i < df->nb_columns; i++) {
        df->columns[i].name = NULL;
        df->columns[i].type = UNDEFINED;
    }
}

static void free_on_error(dataframe_t *df, int cols_alloc)
{
    int j;

    for (j = 0; j < cols_alloc; j++)
        free(df->columns[j].values);
    free(df->columns);
    free(df);
}

bool allocate_all_column_values(dataframe_t *df)
{
    int i = 0;

    for (i = 0; i < df->nb_columns; i++) {
        if (!allocate_column_values(df, i, df->nb_rows))
            return false;
    }
    return true;
}

dataframe_t *create_dataframe_utils(int nb_rows, int nb_columns)
{
    dataframe_t *df;

    df = malloc(sizeof(dataframe_t));
    if (!df)
        return NULL;
    df->nb_rows = nb_rows;
    df->nb_columns = nb_columns;
    df->columns = malloc(sizeof(column_t) * nb_columns);
    if (!df->columns) {
        free(df);
        return NULL;
    }
    init_columns(df);
    if (!alloc_col_values(df, nb_rows)) {
        free_on_error(df, df->nb_columns);
        return NULL;
    }
    return df;
}
