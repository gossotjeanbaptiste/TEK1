/*
** EPITECH PROJECT, 2025
** Bootstrap-Cuddle
** File description:
** df_shape
*/

#include "include/dataframe.h"
#include "include/my.h"
#include <fcntl.h>

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_shape_t shape;

    shape.nb_rows = dataframe->nb_rows;
    shape.nb_columns = dataframe->nb_columns;
    return shape;
}
