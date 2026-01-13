/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_read_csv function (part 3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/dataframe.h"
#include "../../include/utils.h"

static bool check_file(FILE *file, char *sep)
{
    if (!file) {
        handle_error("Cannot open file", NULL, sep);
        return false;
    }
    return true;
}

static void cleanup_resources(FILE *file, char *sep, dataframe_t *df)
{
    if (file)
        fclose(file);
    if (sep)
        free(sep);
    if (df)
        df_free(df);
}

static dataframe_t *process_csv(FILE *file, char *sep, int nb_lines)
{
    char **header = NULL;
    dataframe_t *df = NULL;

    if (!read_and_parse_header(file, sep, &header))
        return NULL;
    df = prepare_dataframe(file, sep, nb_lines, header);
    free_tokens(header);
    if (!df)
        return NULL;
    if (!read_and_process_data(file, sep, df, nb_lines)) {
        df_free(df);
        return NULL;
    }
    return df;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    FILE *file = fopen(filename, "r");
    char *sep = (separator) ? strdup(separator) : strdup(",");
    int nb_lines;
    dataframe_t *df = NULL;

    if (!check_file(file, sep)) {
        cleanup_resources(file, sep, NULL);
        return NULL;
    }
    if (!validate_file(file, &nb_lines)) {
        cleanup_resources(file, sep, NULL);
        return NULL;
    }
    df = process_csv(file, sep, nb_lines);
    cleanup_resources(file, sep, NULL);
    return df;
}
