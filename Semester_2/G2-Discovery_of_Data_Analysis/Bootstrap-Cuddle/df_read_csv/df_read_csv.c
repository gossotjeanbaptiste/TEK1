/*
** EPITECH PROJECT, 2025
** Bootstrap-Cuddle
** File description:
** df_read_csv
*/

#include "../include/dataframe.h"
#include "../include/my.h"
#include <fcntl.h>

static void caller(FILE *ptr, const char *separator, dataframe_t *df)
{
    reader(ptr, separator, df);
    determine_column_types(df);
    convert_data(df);
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    FILE *ptr = fopen(filename, "r");
    dataframe_t *df = malloc(sizeof(dataframe_t));

    if (ptr == NULL) {
        perror("Error opening file");
        return NULL;
    }
    if (df == NULL) {
        fclose(ptr);
        return NULL;
    }
    df->nb_rows = 0;
    df->nb_columns = 0;
    df->column_names = NULL;
    df->column_types = NULL;
    df->data = NULL;
    caller(ptr, separator, df);
    fclose(ptr);
    return df;
}
