#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dataframe.h"

bool sort_func(void *value1, void *value2)
{
    return *(int *)value1 > *(int *)value2;
}

bool sort_func_float(void *value1, void *value2)
{
    return *(float *)value1 > *(float *)value2;
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv", NULL);
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    dataframe_t *sorted = df_sort(dataframe, "age", sort_func);
    
    if (!sorted) {
        fprintf(stderr, "Failed to sort dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(sorted, "sorted.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(sorted);
        return 84;
    }
    
    printf("Successfully sorted dataframe\n");
    
    dataframe_t *types_df = df_read_csv("tests/types.csv", NULL);
    
    if (!types_df) {
        fprintf(stderr, "Failed to read types CSV file\n");
        df_free(dataframe);
        df_free(sorted);
        return 84;
    }
    
    dataframe_t *sorted_float = df_sort(types_df, "float", sort_func_float);
    
    if (!sorted_float) {
        fprintf(stderr, "Failed to sort dataframe with float values\n");
        df_free(dataframe);
        df_free(sorted);
        df_free(types_df);
        return 84;
    }
    
    result = df_write_csv(sorted_float, "sorted_float.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(sorted);
        df_free(types_df);
        df_free(sorted_float);
        return 84;
    }
    
    printf("Successfully sorted dataframe with float values\n");
    
    df_free(dataframe);
    df_free(sorted);
    df_free(types_df);
    df_free(sorted_float);
    return 0;
}