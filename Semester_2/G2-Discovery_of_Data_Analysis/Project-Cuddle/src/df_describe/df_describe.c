/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_describe function
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/dataframe.h"
#include "../../include/utils.h"

void df_describe(dataframe_t *dataframe)
{
    if (!dataframe)
        return;
    describe_all_columns(dataframe);
}
