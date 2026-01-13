/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_read_csv function (part 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/dataframe.h"
#include "../../include/utils.h"

bool validate_file(FILE *file, int *nb_lines)
{
    *nb_lines = count_lines(file);
    if (*nb_lines <= 1) {
        handle_error("Empty file or no data", file, NULL);
        return false;
    }
    return true;
}

static bool check_dataframe(dataframe_t *df, FILE *file, char **header)
{
    if (!df) {
        handle_error("Cannot create dataframe", file, NULL);
        free_tokens(header);
        return false;
    }
    return true;
}

static bool check_column_names(dataframe_t *df, FILE *file, char **header)
{
    if (!set_column_names(df, header)) {
        handle_error("Cannot set column names", file, NULL);
        df_free(df);
        free_tokens(header);
        return false;
    }
    return true;
}

dataframe_t *prepare_dataframe(FILE *file, const char *separator,
    int nb_lines, char **header)
{
    int nb_columns = count_columns(header);
    dataframe_t *df = create_dataframe(nb_lines - 1, nb_columns);

    (void)separator;
    if (!check_dataframe(df, file, header))
        return NULL;
    if (!check_column_names(df, file, header))
        return NULL;
    return df;
}

bool read_and_process_data(FILE *file, const char *sep,
    dataframe_t *df, int nb_lines)
{
    char ***data = read_data(file, sep, nb_lines);

    if (!data) {
        handle_error("Cannot read data", file, NULL);
        return false;
    }
    process_data(df, data, nb_lines, df->nb_columns);
    free_data(data, nb_lines - 1);
    return true;
}
