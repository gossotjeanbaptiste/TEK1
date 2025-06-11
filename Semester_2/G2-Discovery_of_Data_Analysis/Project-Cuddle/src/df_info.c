/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_info function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/dataframe.h"
#include "../include/utils.h"

void df_info(dataframe_t *dataframe)
{
    int i = 0;

    if (!dataframe)
        return;
    printf("%d columns:\n", dataframe->nb_columns);
    for (i = 0; i < dataframe->nb_columns; i++) {
        printf("- %s: %s\n", dataframe->columns[i].name,
            get_type_name(dataframe->columns[i].type));
    }
}
