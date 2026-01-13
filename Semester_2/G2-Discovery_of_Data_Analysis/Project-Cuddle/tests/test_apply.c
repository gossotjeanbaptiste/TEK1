#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"

void *apply_func(void *value)
{
    int *new_value = malloc(sizeof(int));
    *new_value = *(int *)value * 2;
    return new_value;
}

void *apply_func_float(void *value)
{
    float *new_value = malloc(sizeof(float));
    *new_value = *(float *)value * 2.0;
    return new_value;
}

void *apply_func_string(void *value)
{
    char *str = (char *)value;
    char *new_str = strdup(str);
    
    if (new_str && strlen(new_str) > 0 && new_str[strlen(new_str) - 1] == 'e') {
        new_str[strlen(new_str) - 1] = '\0';
    }
    
    return new_str;
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv", NULL);
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    dataframe_t *applied = df_apply(dataframe, "age", apply_func);
    
    if (!applied) {
        fprintf(stderr, "Failed to apply function to dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(applied, "applied.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(applied);
        return 84;
    }
    
    printf("Successfully applied function to dataframe\n");
    
    dataframe_t *types_df = df_read_csv("tests/types.csv", NULL);
    
    if (!types_df) {
        fprintf(stderr, "Failed to read types CSV file\n");
        df_free(dataframe);
        df_free(applied);
        return 84;
    }
    
    dataframe_t *applied_float = df_apply(types_df, "float", apply_func_float);
    
    if (!applied_float) {
        fprintf(stderr, "Failed to apply function to dataframe with float values\n");
        df_free(dataframe);
        df_free(applied);
        df_free(types_df);
        return 84;
    }
    
    result = df_write_csv(applied_float, "applied_float.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(applied);
        df_free(types_df);
        df_free(applied_float);
        return 84;
    }
    
    printf("Successfully applied function to dataframe with float values\n");
    
    dataframe_t *money_df = df_read_csv("tests/money.csv", NULL);
    
    if (!money_df) {
        fprintf(stderr, "Failed to read money CSV file\n");
        df_free(dataframe);
        df_free(applied);
        df_free(types_df);
        df_free(applied_float);
        return 84;
    }
    
    dataframe_t *applied_string = df_apply(money_df, "amount", apply_func_string);
    
    if (!applied_string) {
        fprintf(stderr, "Failed to apply function to dataframe with string values\n");
        df_free(dataframe);
        df_free(applied);
        df_free(types_df);
        df_free(applied_float);
        df_free(money_df);
        return 84;
    }
    
    result = df_write_csv(applied_string, "applied_string.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(applied);
        df_free(types_df);
        df_free(applied_float);
        df_free(money_df);
        df_free(applied_string);
        return 84;
    }
    
    printf("Successfully applied function to dataframe with string values\n");
    
    df_free(dataframe);
    df_free(applied);
    df_free(types_df);
    df_free(applied_float);
    df_free(money_df);
    df_free(applied_string);
    return 0;
}