/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** File utility functions for the Cuddle library
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

char *read_line(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, file);
    if (read == -1) {
        free(line);
        return NULL;
    }
    if (line[read - 1] == '\n')
        line[read - 1] = '\0';
    return line;
}

static void free_data_row(char **row)
{
    if (!row)
        return;
    for (int j = 0; row[j]; j++)
        free(row[j]);
    free(row);
}

void free_data(char ***data, int nb_lines)
{
    if (!data)
        return;
    for (int i = 0; i < nb_lines; i++)
        free_data_row(data[i]);
    free(data);
}

char **read_line_and_split(FILE *file, const char *separator)
{
    char *line = read_line(file);
    char **tokens = NULL;

    if (!line)
        return NULL;
    tokens = split_line(line, separator);
    free(line);
    return tokens;
}
