/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_free function
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

static void free_column_values(void **values, int nb_rows)
{
    int j = 0;

    if (!values)
        return;
    for (j = 0; j < nb_rows; j++) {
        if (values[j]) {
            free(values[j]);
            values[j] = NULL;
        }
    }
    free(values);
}

static void free_columns(column_t *columns, int nb_columns, int nb_rows)
{
    int i = 0;

    if (!columns)
        return;
    for (i = 0; i < nb_columns; i++) {
        if (columns[i].name) {
            free(columns[i].name);
            columns[i].name = NULL;
        }
        free_column_values(columns[i].values, nb_rows);
        columns[i].values = NULL;
    }
    free(columns);
}

void df_free(dataframe_t *dataframe)
{
    if (!dataframe)
        return;
    if (!dataframe->columns || dataframe->nb_columns <= 0 ||
        dataframe->nb_rows <= 0) {
        if (dataframe->separator)
            free(dataframe->separator);
        free(dataframe);
        return;
    }
    free_columns(dataframe->columns, dataframe->nb_columns,
        dataframe->nb_rows);
    dataframe->columns = NULL;
    if (dataframe->separator) {
        free(dataframe->separator);
        dataframe->separator = NULL;
    }
    free(dataframe);
}
