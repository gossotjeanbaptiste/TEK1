/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_write_csv function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/dataframe.h"
#include "../include/utils.h"

static bool validate_write_params(FILE *file, dataframe_t *dataframe)
{
    if (!file) {
        fprintf(stderr, "Error: Cannot open file for writing\n");
        return false;
    }
    if (!dataframe) {
        fprintf(stderr, "Error: Dataframe is NULL\n");
        fclose(file);
        return false;
    }
    return true;
}

const char *get_sep(dataframe_t *dataframe)
{
    return (dataframe && dataframe->separator) ? dataframe->separator : ",";
}

void write_header(FILE *file, dataframe_t *dataframe)
{
    int i = 0;
    const char *sep = get_sep(dataframe);

    for (i = 0; i < dataframe->nb_columns; i++) {
        fprintf(file, "%s", dataframe->columns[i].name);
        if (i < dataframe->nb_columns - 1)
            fprintf(file, "%s", sep);
    }
    fprintf(file, "\n");
}

void write_row(FILE *file, dataframe_t *dataframe, int row_idx)
{
    int j = 0;
    const char *sep = get_sep(dataframe);

    for (j = 0; j < dataframe->nb_columns; j++) {
        write_value(file, dataframe->columns[j].values[row_idx],
            dataframe->columns[j].type);
        if (j < dataframe->nb_columns - 1)
            fprintf(file, "%s", sep);
    }
    fprintf(file, "\n");
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    FILE *file = fopen(filename, "w");
    int i = 0;

    if (!validate_write_params(file, dataframe))
        return -1;
    write_header(file, dataframe);
    for (i = 0; i < dataframe->nb_rows; i++)
        write_row(file, dataframe, i);
    fclose(file);
    return 0;
}
