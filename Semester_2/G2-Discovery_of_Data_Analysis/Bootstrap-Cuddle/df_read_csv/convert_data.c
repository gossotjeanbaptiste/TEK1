/*
** EPITECH PROJECT, 2025
** Bootstrap-Cuddle
** File description:
** convert_data
*/

#include "../include/dataframe.h"
#include "../include/my.h"
#include <fcntl.h>

static void switch_conv_data(dataframe_t *df, int col, int row, char *value)
{
    switch (df->column_types[col]) {
    case BOOL:
        df->data[row][col] =
            (void *)(intptr_t)(strcmp(value, "true") == 0);
        break;
    case INT:
        df->data[row][col] = (void *)(intptr_t)atoi(value);
        break;
    case UINT:
        df->data[row][col] =
            (void *)(uintptr_t)strtoul(value, NULL, 10);
        break;
    case FLOAT:
        df->data[row][col] =
            (void *)(intptr_t)strtod(value, NULL);
        break;
    default:
        df->data[row][col] = strdup(value);
        break;
    }
}

void convert_data(dataframe_t *df)
{
    char *value;

    for (int row = 0; row < df->nb_rows; row++) {
        for (int col = 0; col < df->nb_columns; col++) {
            value = (char *)df->data[row][col];
            switch_conv_data(df, col, row, value);
            free(value);
        }
    }
}
