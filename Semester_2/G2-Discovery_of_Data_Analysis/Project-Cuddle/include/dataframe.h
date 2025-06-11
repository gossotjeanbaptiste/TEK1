/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Header file for the Cuddle library
*/

#ifndef DATAFRAME_H_
    #define DATAFRAME_H_

    #include <stdbool.h>
    #include <stdio.h>

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct {
    float mean;
    float std;
    float min;
    float max;
} column_stats_t;

typedef struct column_s {
    char *name;
    column_type_t type;
    void **values;
} column_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    column_t *columns;
    char *separator;
} dataframe_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

typedef struct {
    void **values;
    int *indices;
    int size;
    bool (*sort_func)(void *value1, void *value2);
} sort_context_t;

typedef struct {
    void **values;
    int nb_rows;
    column_type_t type;
    float mean;
    int *count;
} sum_squared_ctx_t;

dataframe_t *df_read_csv(const char *filename, const char *separator);
int df_write_csv(dataframe_t *dataframe, const char *filename);

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
dataframe_shape_t df_shape(dataframe_t *dataframe);
void df_info(dataframe_t *dataframe);
void df_describe(dataframe_t *dataframe);

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value));
dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_func)(void *value1, void *value2));

dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate,
    void *(*agg_func)(void **values, int nb_values));
dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value));
dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast);

void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);
void df_free(dataframe_t *dataframe);

float get_numeric_value(void *value, column_type_t type);
bool is_numeric_type(column_type_t type);

typedef struct {
    void **values;
    int rows;
    column_type_t type;
    float mean;
} calc_std_ctx_t;

float calc_mean(void **values, int rows, column_type_t type);
float calc_std(calc_std_ctx_t ctx);
float get_min(void **values, int rows, column_type_t type);
float get_max(void **values, int rows, column_type_t type);

typedef struct {
    const char *name;
    int count;
    float mean;
    float std;
    float min;
    float max;
} column_stats_info_t;

typedef struct {
    column_t column;
    int nb_rows;
    float *mean;
    float *std;
    float *min;
    float *max;
} calculate_stats_ctx_t;

void print_col_stats(column_stats_info_t stats);

void describe_column(dataframe_t *df, int col_idx);

void *copy_value_head(void *value, column_type_t type);

int find_column_idx_internal(dataframe_t *dataframe, const char *column_name);

bool values_are_equal(void *value1, void *value2, column_type_t type);
bool is_value_unique_utils(void **values, int index, column_type_t type);
int count_unique(void **values, int nb_rows, column_type_t type);
#endif /* !DATAFRAME_H_ */
