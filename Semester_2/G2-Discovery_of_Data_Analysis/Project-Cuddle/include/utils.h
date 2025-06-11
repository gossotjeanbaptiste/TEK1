/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Internal utility functions for the Cuddle library
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <stdio.h>
    #include <stdbool.h>
    #include "dataframe.h"

bool is_numeric(const char *str);
bool is_float(const char *str);
bool is_bool(const char *str);
void free_tokens(char **tokens);
char **split_line(const char *line, const char *separator);
int count_tokens(const char *line, const char *separator);
const char *get_sep(dataframe_t *dataframe);

char *read_line(FILE *file);
int count_lines(FILE *file);
char ***read_data(FILE *file, const char *separator, int nb_lines);
void free_data(char ***data, int nb_lines);
char **read_line_and_split(FILE *file, const char *separator);

typedef struct {
    char **values;
    int nb_rows;
    bool *has_negative;
    bool *all_int;
    bool *all_float;
} check_numeric_ctx_t;

typedef struct {
    char **values;
    int nb_rows;
    bool *all_bool;
} check_bool_ctx_t;
const char *get_type_name(column_type_t type);
column_type_t detect_column_type(char **values, int nb_rows);
void *convert_value(const char *value, column_type_t type);

void *copy_value(void *value, column_type_t type);

int find_col_idx(dataframe_t *df, const char *col_name);
dataframe_t *copy_df_struct(dataframe_t *df);
bool alloc_col_vals(dataframe_t *df, int i, int rows);

void sort_indices(sort_context_t *ctx);
bool init_sort_ctx(sort_context_t *ctx, dataframe_t *df, int col_idx);
void copy_sorted_vals(dataframe_t *sorted, dataframe_t *src, int *indices);

int count_filtered_rows(dataframe_t *df, int col_idx,
    bool (*filter_func)(void *));
void copy_filtered_vals(dataframe_t *filtered, dataframe_t *src,
    int col_idx, bool (*filter_func)(void *));
dataframe_t *create_filtered_df(dataframe_t *df, int col_idx,
    int filtered_rows, bool (*filter_func)(void *));

int find_column_index(dataframe_t *dataframe, const char *column_name);
bool is_value_unique(char **unique_values, int count, const char *value);
void free_unique_values(char **unique_values, int count);
int count_unique_values(dataframe_t *dataframe, int col_idx);
bool add_unique_value(char **unique_values, int *count, const char *value);

typedef struct {
    dataframe_t *dataframe;
    int col_idx;
    int agg_col_idx;
    const char *group_value;
    int *count;
} collect_values_ctx_t;

char **get_unique_values(dataframe_t *dataframe, int col_idx, int *count);
void **collect_values_for_group(collect_values_ctx_t ctx);
bool init_result_columns(dataframe_t *result, const char *aggregate_by,
    const char *to_aggregate, column_type_t type);
dataframe_t *create_result_dataframe(int unique_count);

typedef struct {
    dataframe_t *result;
    void **values;
    int count;
    int i;
    void *(*agg_func)(void **, int);
} apply_aggregation_ctx_t;
typedef struct {
    dataframe_t *result;
    dataframe_t *dataframe;
    int col_idx;
    int agg_col_idx;
    char **unique_values;
    int i;
    void *(*agg_func)(void **, int);
} process_group_ctx_t;

typedef struct {
    dataframe_t *result;
    int processed_rows;
    char **unique_values;
    int unique_count;
} partial_result_ctx_t;

void free_partial_result(partial_result_ctx_t ctx);
bool process_group(process_group_ctx_t ctx);
typedef struct {
    dataframe_t *result;
    dataframe_t *dataframe;
    int col_idx;
    int agg_col_idx;
    char **unique_values;
    int unique_count;
    void *(*agg_func)(void **, int);
} process_all_groups_ctx_t;

typedef struct {
    dataframe_t *result;
    dataframe_t *dataframe;
    int col_idx;
    int agg_col_idx;
    char **unique_values;
    int unique_count;
    void *(*agg_func)(void **, int);
} group_process_ctx_t;

typedef struct {
    dataframe_t *dataframe;
    const char *aggregate_by;
    const char **to_aggregate;
    int col_idx;
    int agg_col_idx;
    int unique_count;
    void *(*agg_func)(void **, int);
} groupby_ctx_t;

bool process_all_groups(process_all_groups_ctx_t ctx);


bool allocate_column_values(dataframe_t *df, int i, int rows);
void *process_value(void *value, bool should_apply,
    void *(*apply_func)(void *), column_type_t type);
bool allocate_all_column_values(dataframe_t *df);
typedef struct {
    dataframe_t *result;
    dataframe_t *src;
    int col_idx;
    void *(*apply_func)(void *);
    int i;
} process_column_values_ctx_t;

typedef struct {
    dataframe_t *filtered;
    dataframe_t *src;
    int col_idx;
    int col_i;
} filter_copy_ctx_t;

void process_column_values(process_column_values_ctx_t ctx);
bool copy_applied_values(dataframe_t *result, dataframe_t *src, int col_idx,
    void *(*apply_func)(void *));
dataframe_t *create_apply_result_dataframe(dataframe_t *dataframe);

float get_numeric_value(void *value, column_type_t type);
bool is_numeric_type(column_type_t type);
float calc_mean(void **values, int rows, column_type_t type);
float calc_std(calc_std_ctx_t ctx);
float get_min(void **values, int rows, column_type_t type);

float get_max(void **values, int rows, column_type_t type);
void print_col_stats(column_stats_info_t stats);
void describe_column(dataframe_t *df, int col_idx);
void describe_all_columns(dataframe_t *df);

dataframe_t *create_dataframe(int nb_rows, int nb_columns);
dataframe_t *create_dataframe_utils(int nb_rows, int nb_columns);
void process_data(dataframe_t *df, char ***data, int nb_lines, int nb_columns);
void handle_error(const char *message, FILE *file,
    __attribute__((unused)) char *sep);
bool set_column_names(dataframe_t *df, char **header);
int count_columns(char **header);

bool read_and_parse_header(FILE *file, const char *sep, char ***header_ptr);
bool validate_file(FILE *file, int *nb_lines);
dataframe_t *prepare_dataframe(FILE *file, const char *separator,
    int nb_lines, char **header);
bool read_and_process_data(FILE *file, const char *sep,
    dataframe_t *df, int nb_lines);

void write_value(FILE *file, void *value, column_type_t type);
void write_bool_value(FILE *file, void *value);
void write_int_value(FILE *file, void *value);
void write_uint_value(FILE *file, void *value);
void write_float_value(FILE *file, void *value);
void write_string_value(FILE *file, void *value);

bool can_convert_to_type(const char *value, column_type_t type);
void *copy_value_type(void *value, column_type_t type);
dataframe_t *copy_dataframe_structure(dataframe_t *dataframe);

bool validate_inputs(dataframe_t *dataframe, FILE *file);
void write_header(FILE *file, dataframe_t *dataframe);
void write_row(FILE *file, dataframe_t *dataframe, int row_idx);

#endif /* !UTILS_H_ */
