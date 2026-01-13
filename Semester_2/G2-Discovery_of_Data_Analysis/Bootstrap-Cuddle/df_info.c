/*
** EPITECH PROJECT, 2025
** Bootstrap-Cuddle
** File description:
** df_info
*/

#include "include/dataframe.h"
#include "include/my.h"
#include <fcntl.h>

static void switch_info(dataframe_t *df, int i)
{
    switch (df->column_types[i]) {
    case BOOL:
        printf("bool\n");
        break;
    case INT:
        printf("int\n");
        break;
    case UINT:
        printf("uint\n");
        break;
    case FLOAT:
        printf("float\n");
        break;
    default:
        printf("string\n");
        break;
    }
}

void df_info(dataframe_t *df)
{
    printf("%d columns :\n", df->nb_columns);
    for (int i = 0; i < df->nb_columns; i++) {
        printf("- %s : ", df->column_names[i]);
        switch_info(df, i);
    }
}
