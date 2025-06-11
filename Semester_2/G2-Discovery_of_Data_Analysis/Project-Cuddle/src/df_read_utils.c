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
#include "../include/dataframe.h"
#include "../include/utils.h"

/*static void free_line_data(char **line_data)
{
    int j = 0;

    if (!line_data)
        return;
    for (j = 0; line_data[j]; j++)
        free(line_data[j]);
    free(line_data);
}*/

static bool process_line(char ***data, int i, FILE *file,
    const char *separator)
{
    char *line = read_line(file);

    if (!line) {
        free_data(data, i);
        return false;
    }
    data[i] = split_line(line, separator);
    free(line);
    if (!data[i]) {
        free_data(data, i);
        return false;
    }
    return true;
}

char ***read_data(FILE *file, const char *separator, int nb_lines)
{
    char ***data = malloc(sizeof(char **) * (nb_lines - 1));
    int i = 0;

    if (!data)
        return NULL;
    for (i = 0; i < nb_lines - 1; i++) {
        if (!process_line(data, i, file, separator))
            return NULL;
    }
    return data;
}
