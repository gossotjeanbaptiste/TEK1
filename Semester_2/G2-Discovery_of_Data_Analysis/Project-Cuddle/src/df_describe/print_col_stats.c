/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Implementation of df_describe function (part 5)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../../include/dataframe.h"

static void print_column_header(const char *name, int count)
{
    printf("Column: %s\n", name);
    printf("Count: %d\n", count);
}

static void print_stats_values(double mean, double std, double min, double max)
{
    printf("Mean: %.2f\n", mean);
    printf("Std: %.2f\n", std);
    printf("Min: %.2f\n", min);
    printf("Max: %.2f\n", max);
}

void print_col_stats(column_stats_info_t stats)
{
    print_column_header(stats.name, stats.count);
    print_stats_values(stats.mean, stats.std, stats.min, stats.max);
}
