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
    
    dataframe_t *tail = df_tail(dataframe, 3);
    
    if (!tail) {
        fprintf(stderr, "Failed to get tail of dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(tail, "tail.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(tail);
        return 84;
    }
    
    printf("Successfully created tail of dataframe\n");
    df_free(dataframe);
    df_free(tail);
    return 0;
}