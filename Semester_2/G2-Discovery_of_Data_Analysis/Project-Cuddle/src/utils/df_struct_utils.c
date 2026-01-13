/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Dataframe structure utility functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/utils.h"

int find_col_idx(dataframe_t *df, const char *col_name)
{
    int i;

    if (!df || !col_name)
        return -1;
    for (i = 0; i < df->nb_columns; i++) {
        if (strcmp(df->columns[i].name, col_name) == 0)
            return i;
    }
    return -1;
}

static bool alloc_col_name(dataframe_t *df, int i, dataframe_t *src)
{
    df->columns[i].name = strdup(src->columns[i].name);
    df->columns[i].type = src->columns[i].type;
    return (df->columns[i].name != NULL);
}

static void free_col_names(dataframe_t *df, int count)
{
    int j;

    for (j = 0; j < count; j++)
        free(df->columns[j].name);
}

static dataframe_t *handle_alloc_failure(dataframe_t *new_df, int i)
{
    free_col_names(new_df, i);
    free(new_df->columns);
    free(new_df);
    return NULL;
}

dataframe_t *copy_df_struct(dataframe_t *df)
{
    dataframe_t *new_df;
    int i;

    new_df = malloc(sizeof(dataframe_t));
    if (!new_df)
        return NULL;
    new_df->nb_columns = df->nb_columns;
    new_df->columns = malloc(sizeof(column_t) * new_df->nb_columns);
    if (!new_df->columns) {
        free(new_df);
        return NULL;
    }
    for (i = 0; i < new_df->nb_columns; i++) {
        if (!alloc_col_name(new_df, i, df))
            return handle_alloc_failure(new_df, i);
    }
    return new_df;
}

bool alloc_col_vals(dataframe_t *df, int i, int rows)
{
    df->columns[i].values = malloc(sizeof(void *) * rows);
    return (df->columns[i].values != NULL);
}
