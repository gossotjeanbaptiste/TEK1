/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_head function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"

static bool allocate_column_name(dataframe_t *df, int i, dataframe_t *src)
{
    df->columns[i].name = strdup(src->columns[i].name);
    df->columns[i].type = src->columns[i].type;
    return (df->columns[i].name != NULL);
}

static void free_column_names(dataframe_t *df, int count)
{
    int j = 0;

    for (j = 0; j < count; j++)
        free(df->columns[j].name);
}

static dataframe_t *copy_dataframe_structure(dataframe_t *dataframe)
{
    dataframe_t *new_df = malloc(sizeof(dataframe_t));
    int i = 0;

    if (!new_df)
        return NULL;
    new_df->nb_columns = dataframe->nb_columns;
    new_df->columns = malloc(sizeof(column_t) * new_df->nb_columns);
    if (!new_df->columns) {
        free(new_df);
        return NULL;
    }
    for (i = 0; i < new_df->nb_columns; i++) {
        if (!allocate_column_name(new_df, i, dataframe)) {
            free_column_names(new_df, i);
            free(new_df->columns);
            free(new_df);
            return NULL;
        }
    }
    return new_df;
}

static bool allocate_column_values(dataframe_t *df, int i, int rows)
{
    df->columns[i].values = malloc(sizeof(void *) * rows);
    return (df->columns[i].values != NULL);
}

static void copy_head_values(dataframe_t *head, dataframe_t *src)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < head->nb_columns; i++) {
        if (!allocate_column_values(head, i, head->nb_rows)) {
            df_free(head);
            return;
        }
        for (j = 0; j < head->nb_rows; j++) {
            head->columns[i].values[j] = copy_value_head(
                src->columns[i].values[j],
                src->columns[i].type);
        }
    }
}

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *head;
    int rows_to_copy;

    if (!dataframe || nb_rows <= 0)
        return NULL;
    rows_to_copy = (nb_rows < dataframe->nb_rows) ? nb_rows :
        dataframe->nb_rows;
    head = copy_dataframe_structure(dataframe);
    if (!head)
        return NULL;
    head->nb_rows = rows_to_copy;
    copy_head_values(head, dataframe);
    return head;
}
