/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Groupby utility functions (part 1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

int find_column_index(dataframe_t *dataframe, const char *column_name)
{
    int i = 0;

    if (!dataframe || !column_name)
        return -1;
    for (i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->columns[i].name, column_name) == 0)
            return i;
    }
    return -1;
}

bool is_value_unique(char **unique_values, int count, const char *value)
{
    int j = 0;

    for (j = 0; j < count; j++) {
        if (strcmp(value, unique_values[j]) == 0)
            return false;
    }
    return true;
}

void free_unique_values(char **unique_values, int count)
{
    int i = 0;

    for (i = 0; i < count; i++)
        free(unique_values[i]);
    free(unique_values);
}

int count_unique_values(dataframe_t *dataframe, int col_idx)
{
    int count = 0;
    int i = 0;
    bool is_unique = false;
    char **unique_values = malloc(sizeof(char *) * dataframe->nb_rows);

    if (!unique_values)
        return 0;
    for (i = 0; i < dataframe->nb_rows; i++) {
        is_unique = is_value_unique(unique_values, count,
            (char *)dataframe->columns[col_idx].values[i]);
        if (is_unique) {
            unique_values[count] = strdup(
                (char *)dataframe->columns[col_idx].values[i]);
            count++;
        }
    }
    free_unique_values(unique_values, count);
    return count;
}

bool add_unique_value(char **unique_values, int *count, const char *value)
{
    unique_values[*count] = strdup(value);
    if (!unique_values[*count])
        return false;
    (*count)++;
    return true;
}
