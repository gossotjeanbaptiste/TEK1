/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_read_csv function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/dataframe.h"
#include "../../include/utils.h"

static bool check_file_validity(FILE *file, int *nb_lines, char *sep)
{
    if (!file) {
        handle_error("Cannot open file", NULL, sep);
        return false;
    }
    *nb_lines = count_lines(file);
    if (*nb_lines <= 1) {
        handle_error("Empty file or no data", file, sep);
        return false;
    }
    return true;
}

static bool init_df_columns(dataframe_t *df, char **header)
{
    if (!set_column_names(df, header)) {
        handle_error("Cannot set column names", NULL, NULL);
        return false;
    }
    return true;
}

static bool process_csv_data(dataframe_t *df, FILE *file, char *sep, int lines)
{
    char ***data = read_data(file, sep, lines);

    if (!data) {
        handle_error("Cannot read data", file, sep);
        return false;
    }
    process_data(df, data, lines, df->nb_columns);
    free_data(data, lines - 1);
    return true;
}

static void cleanup_resources(FILE *file, char *sep, dataframe_t *df,
    char **header)
{
    if (header)
        free_tokens(header);
    if (file)
        fclose(file);
    if (sep)
        free(sep);
    if (df)
        df_free(df);
}

static dataframe_t *create_df(FILE *file, char *sep, char **header, int lines)
{
    int nb_columns = count_columns(header);
    dataframe_t *df = create_dataframe(lines - 1, nb_columns);

    if (!df) {
        handle_error("Cannot create dataframe", file, sep);
        return NULL;
    }
    if (!init_df_columns(df, header)) {
        df_free(df);
        return NULL;
    }
    return df;
}

static dataframe_t *init_and_process_df(FILE *file, char *sep,
    char **header, int nb_lines)
{
    dataframe_t *df = create_df(file, sep, header, nb_lines);

    if (!df || !process_csv_data(df, file, sep, nb_lines))
        return NULL;
    return df;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    FILE *file = fopen(filename, "r");
    char *sep = strdup(separator ? separator : ",");
    char **header = NULL;
    int nb_lines = 0;
    dataframe_t *df = NULL;

    if (!check_file_validity(file, &nb_lines, sep) ||
        !read_and_parse_header(file, sep, &header))
        return (cleanup_resources(file, sep, NULL, header), NULL);
    df = init_and_process_df(file, sep, header, nb_lines);
    if (!df)
        return (cleanup_resources(file, sep, df, header), NULL);
    df->separator = strdup(sep);
    free_tokens(header);
    fclose(file);
    free(sep);
    return df;
}
