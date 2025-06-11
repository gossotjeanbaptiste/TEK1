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
    
    dataframe_t *head = df_head(dataframe, 3);
    
    if (!head) {
        fprintf(stderr, "Failed to get head of dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(head, "head.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(head);
        return 84;
    }
    
    printf("Successfully created head of dataframe\n");
    df_free(dataframe);
    df_free(head);
    return 0;
}