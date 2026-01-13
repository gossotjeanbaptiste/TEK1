/*
** EPITECH PROJECT, 2025
** Bootstrap-Cuddle
** File description:
** dataframe
*/

#ifndef INCLUDED_DATAFRAME_H
    #define INCLUDED_DATAFRAME_H
    #include <string.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
} dataframe_t;

typedef struct {
    int is_int_col;
    int is_uint_col;
    int is_float_col;
    int is_bool_col;
    char *value;
} determine_t;

typedef struct dataframe_shape {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

void df_info(dataframe_t *df);
dataframe_shape_t df_shape(dataframe_t *dataframe);
void convert_data(dataframe_t *df);
void reader(FILE *ptr, const char *separator, dataframe_t *df);
void determine_column_types(dataframe_t *df);
dataframe_t *df_read_csv(const char *filename, const char *separator);
void caller(FILE *ptr, const char *separator, dataframe_t *df);
#endif
