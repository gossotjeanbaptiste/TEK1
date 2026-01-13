/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_read_csv function (part 1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/dataframe.h"
#include "../../include/utils.h"

static char *read_header_line(FILE *file)
{
    char *line = read_line(file);

    if (!line)
        handle_error("Cannot read header", file, NULL);
    return line;
}

static char **parse_header_line(char *line, const char *sep, FILE *file)
{
    char **header = split_line(line, sep);

    if (!header)
        handle_error("Cannot parse header", file, NULL);
    return header;
}

bool read_and_parse_header(FILE *file, const char *sep, char ***header_ptr)
{
    char *line = read_header_line(file);
    char **header = NULL;

    if (!line)
        return false;
    header = parse_header_line(line, sep, file);
    free(line);
    if (!header)
        return false;
    *header_ptr = header;
    return true;
}

int count_columns(char **header)
{
    int nb_columns = 0;

    while (header[nb_columns])
        nb_columns++;
    return nb_columns;
}

bool set_column_names(dataframe_t *df, char **header)
{
    int i = 0;

    for (i = 0; i < df->nb_columns; i++) {
        df->columns[i].name = strdup(header[i]);
        if (!df->columns[i].name)
            return false;
    }
    return true;
}

static bool allocate_column_values_internal(dataframe_t *df,
    int nb_rows, int i)
{
    int j = 0;

    df->columns[i].name = NULL;
    df->columns[i].type = UNDEFINED;
    df->columns[i].values = malloc(sizeof(void *) * nb_rows);
    if (!df->columns[i].values)
        return false;
    for (j = 0; j < nb_rows; j++)
        df->columns[i].values[j] = NULL;
    return true;
}

static void cleanup_columns(dataframe_t *df, int count)
{
    int j = 0;

    for (j = 0; j < count; j++)
        free(df->columns[j].values);
    free(df->columns);
    free(df);
}

static bool init_columns(dataframe_t *df, int nb_rows, int nb_columns)
{
    int i = 0;

    for (i = 0; i < nb_columns; i++) {
        if (!allocate_column_values_internal(df, nb_rows, i)) {
            cleanup_columns(df, i);
            return false;
        }
    }
    return true;
}

static dataframe_t *allocate_dataframe(int nb_rows, int nb_columns)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));

    if (!df)
        return NULL;
    df->nb_rows = nb_rows;
    df->nb_columns = nb_columns;
    df->columns = malloc(sizeof(column_t) * nb_columns);
    df->separator = strdup(",");
    if (!df->columns) {
        free(df);
        return NULL;
    }
    return df;
}

dataframe_t *create_dataframe(int nb_rows, int nb_columns)
{
    dataframe_t *df = allocate_dataframe(nb_rows, nb_columns);

    if (!df)
        return NULL;
    if (!init_columns(df, nb_rows, nb_columns))
        return NULL;
    return df;
}
