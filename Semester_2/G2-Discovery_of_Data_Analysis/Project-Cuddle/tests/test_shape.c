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
    
    dataframe_shape_t shape = df_shape(dataframe);
    
    printf("Shape: %d rows, %d columns\n", shape.nb_rows, shape.nb_columns);
    
    df_free(dataframe);
    return 0;
}