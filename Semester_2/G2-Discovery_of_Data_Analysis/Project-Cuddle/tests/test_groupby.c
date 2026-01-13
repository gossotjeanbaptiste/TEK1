#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

void *agg_func(void **values, int nb_values)
{
    int *sum = malloc(sizeof(int));
    *sum = 0;
    
    for (int i = 0; i < nb_values; i++) {
        *sum += *(int *)values[i];
    }
    return sum;
}

void *agg_func_float(void **values, int nb_values)
{
    float *sum = malloc(sizeof(float));
    *sum = 0.0;
    
    for (int i = 0; i < nb_values; i++) {
        *sum += *(float *)values[i];
    }
    return sum;
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv", NULL);
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    dataframe_t *grouped = df_groupby(dataframe, "city", (const char *[]){"age", NULL}, agg_func);
    
    if (!grouped) {
        fprintf(stderr, "Failed to group dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(grouped, "grouped.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(grouped);
        return 84;
    }
    
    printf("Successfully grouped dataframe\n");
    
    dataframe_t *types_df = df_read_csv("tests/types.csv", NULL);
    
    if (!types_df) {
        fprintf(stderr, "Failed to read types CSV file\n");
        df_free(dataframe);
        df_free(grouped);
        return 84;
    }
    
    dataframe_t *grouped_float = df_groupby(types_df, "bool", (const char *[]){"float", NULL}, agg_func_float);
    
    if (!grouped_float) {
        fprintf(stderr, "Failed to group dataframe with float values\n");
        df_free(dataframe);
        df_free(grouped);
        df_free(types_df);
        return 84;
    }
    
    result = df_write_csv(grouped_float, "grouped_float.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(grouped);
        df_free(types_df);
        df_free(grouped_float);
        return 84;
    }
    
    printf("Successfully grouped dataframe with float values\n");
    
    df_free(dataframe);
    df_free(grouped);
    df_free(types_df);
    df_free(grouped_float);
    return 0;
}