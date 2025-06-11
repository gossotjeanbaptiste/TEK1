#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv", NULL);
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    printf("Dataframe info:\n");
    df_info(dataframe);
    
    df_free(dataframe);
    
    dataframe_t *types_df = df_read_csv("tests/types.csv", NULL);
    
    if (!types_df) {
        fprintf(stderr, "Failed to read types CSV file\n");
        return 84;
    }
    
    printf("\nTypes dataframe info:\n");
    df_info(types_df);
    
    df_free(types_df);
    return 0;
}