/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Groupby utility functions (part 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

static bool process_unique_value(char **unique_values, int *unique_count,
    char *value)
{
    if (!is_value_unique(unique_values, *unique_count, value))
        return true;
    return add_unique_value(unique_values, unique_count, value);
}

char **get_unique_values(dataframe_t *dataframe, int col_idx, int *count)
{
    int unique_count = 0;
    int i = 0;
    char **unique_values = malloc(sizeof(char *) * dataframe->nb_rows);

    if (!unique_values)
        return NULL;
    for (i = 0; i < dataframe->nb_rows; i++) {
        if (!process_unique_value(unique_values, &unique_count,
            (char *)dataframe->columns[col_idx].values[i])) {
            free_unique_values(unique_values, unique_count);
            return NULL;
        }
    }
    *count = unique_count;
    return unique_values;
}

void **collect_values_for_group(collect_values_ctx_t ctx)
{
    void **values = malloc(sizeof(void *) * ctx.dataframe->nb_rows);
    int value_count = 0;
    int i = 0;

    if (!values)
        return NULL;
    for (i = 0; i < ctx.dataframe->nb_rows; i++) {
        if (strcmp((char *)ctx.dataframe->columns[ctx.col_idx].values[i],
            ctx.group_value) == 0) {
            values[value_count] = ctx.dataframe->
                columns[ctx.agg_col_idx].values[i];
            value_count++;
        }
    }
    *(ctx.count) = value_count;
    return values;
}

bool init_result_columns(dataframe_t *result, const char *aggregate_by,
    const char *to_aggregate, column_type_t type)
{
    result->columns[0].name = strdup(aggregate_by);
    result->columns[0].type = STRING;
    result->columns[0].values = malloc(sizeof(void *) * result->nb_rows);
    result->columns[1].name = strdup(to_aggregate);
    result->columns[1].type = type;
    result->columns[1].values = malloc(sizeof(void *) * result->nb_rows);
    return (result->columns[0].name && result->columns[1].name
        && result->columns[0].values && result->columns[1].values);
}

dataframe_t *create_result_dataframe(int unique_count)
{
    dataframe_t *result = malloc(sizeof(dataframe_t));

    if (!result)
        return NULL;
    result->nb_rows = unique_count;
    result->nb_columns = 2;
    result->columns = malloc(sizeof(column_t) * result->nb_columns);
    if (!result->columns) {
        free(result);
        return NULL;
    }
    return result;
}
