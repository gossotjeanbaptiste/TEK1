#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dataframe.h"

bool filter_func(void *value)
{
    return *(int *)value > 30;
}

bool filter_func_float(void *value)
{
    return *(float *)value > 15.0;
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv", NULL);
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    dataframe_t *filtered = df_filter(dataframe, "age", filter_func);
    
    if (!filtered) {
        fprintf(stderr, "Failed to filter dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(filtered, "filtered.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(filtered);
        return 84;
    }
    
    printf("Successfully filtered dataframe\n");
    
    dataframe_t *types_df = df_read_csv("tests/types.csv", NULL);
    
    if (!types_df) {
        fprintf(stderr, "Failed to read types CSV file\n");
        df_free(dataframe);
        df_free(filtered);
        return 84;
    }
    
    dataframe_t *filtered_float = df_filter(types_df, "float", filter_func_float);
    
    if (!filtered_float) {
        fprintf(stderr, "Failed to filter dataframe with float values\n");
        df_free(dataframe);
        df_free(filtered);
        df_free(types_df);
        return 84;
    }
    
    result = df_write_csv(filtered_float, "filtered_float.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(filtered);
        df_free(types_df);
        df_free(filtered_float);
        return 84;
    }
    
    printf("Successfully filtered dataframe with float values\n");
    
    df_free(dataframe);
    df_free(filtered);
    df_free(types_df);
    df_free(filtered_float);
    return 0;
}