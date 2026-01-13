/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_shape function
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_shape_t shape;

    shape.nb_rows = 0;
    shape.nb_columns = 0;
    if (dataframe) {
        shape.nb_rows = dataframe->nb_rows;
        shape.nb_columns = dataframe->nb_columns;
    }
    return shape;
}
