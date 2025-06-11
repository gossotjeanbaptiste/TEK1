/*
** EPITECH PROJECT, 2025
** Bootstrap-Cuddle
** File description:
** read_content
*/

#include "../include/dataframe.h"
#include "../include/my.h"
#include <fcntl.h>


void reader(FILE *ptr, const char *separator, dataframe_t *df)
{
    read_header(ptr, separator, df);
    read_content(ptr, separator, df);
}

static void read_header(FILE *ptr, const char *separator, dataframe_t *df)
{
    char *line = NULL;
    size_t len = 0;
    char *token;
    ssize_t read = getline(&line, &len, ptr);

    if (read != -1) {
        line[strcspn(line, "\n")] = '\0';
        token = strtok(line, separator);
        while (token != NULL) {
            df->nb_columns++;
            df->column_names = realloc
            (df->column_names, df->nb_columns * sizeof(char *));
            df->column_names[df->nb_columns - 1] = strdup(token);
            token = strtok(NULL, separator);
        }
    }
    free(line);
}

static void read_content(FILE *ptr, const char *separator, dataframe_t *df)
{
    char *line = NULL;
    size_t len = 0;
    char *token;
    ssize_t read = getline(&line, &len, ptr);

    while (read != -1) {
        line[strcspn(line, "\n")] = '\0';
        df->nb_rows++;
        df->data = realloc
        (df->data, df->nb_rows * sizeof(void **));
        df->data[df->nb_rows - 1] = malloc(df->nb_columns * sizeof(void *));
        token = strtok(line, separator);
        for (int i = 0; i < df->nb_columns; i++) {
            df->data[df->nb_rows - 1][i] = strdup(token);
            token = strtok(NULL, separator);
        }
        read = getline(&line, &len, ptr);
    }
    free(line);
}
