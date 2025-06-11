/*
** EPITECH PROJECT, 2024
** Epi-Template-C
** File description:
** Main for Epi-Template-C
*/
#include "include/my.h"
#include "include/dataframe.h"


static void annexe_main(dataframe_t *df, dataframe_shape_t *shape)
{
    for (int i = 0; i < df->nb_rows; i++) {
        df->data[i] = malloc(df->nb_columns * sizeof(void *));
        df->data[i][0] = strdup("John Doe");
        df->data[i][1] = (void *)(intptr_t)(20 + i);
        df->data[i][2] = strdup("New York");
    }
    df_info(df);
    *shape = df_shape(df);
    printf("Shape: %d rows, %d columns\n", shape->nb_rows, shape->nb_columns);
    for (int i = 0; i < df->nb_rows; i++) {
        free(df->data[i][0]);
        free(df->data[i][2]);
        free(df->data[i]);
    }
    free(df->data);
    free(df);
    free(shape);
}

int main(void)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));
    dataframe_shape_t *shape = malloc(sizeof(dataframe_shape_t));

    df->nb_columns = 3;
    df->nb_rows = 5;
    df->column_names = (char *[]){"name", "age", "city"};
    df->column_types = (column_type_t[]){STRING, INT, STRING};
    df->data = malloc(df->nb_rows * sizeof(void **));
    annexe_main(df, shape);
    return 0;
}
