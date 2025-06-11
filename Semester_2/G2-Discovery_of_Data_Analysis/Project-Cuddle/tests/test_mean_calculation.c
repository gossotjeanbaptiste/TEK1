/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Test mean calculation with more then 1 value 
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

void create_test_csv_numeric(void)
{
    FILE *file = fopen("test_numeric.csv", "w");
    if (!file)
        return;
    
    fprintf(file, "id,value1,value2,value3\n");
    fprintf(file, "1,10,20.5,30\n");
    fprintf(file, "2,15,25.7,35\n");
    fprintf(file, "3,20,30.9,40\n");
    fprintf(file, "4,25,35.1,45\n");
    fprintf(file, "5,30,40.3,50\n");
    
    fclose(file);
}

int main(void)
{
    printf("=== Testing mean calculation with more then 1 values ===\n");
    create_test_csv_numeric();
    
    dataframe_t *df = df_read_csv("test_numeric.csv", ",");
    if (!df) {
        printf("Failed to read CSV file\n");
        return 84;
    }
    
    printf("Successfully read CSV file\n");
    printf("Dataframe shape: (%d, %d)\n", df->nb_rows, df->nb_columns);
    
    df_info(df);
    
    printf("\nCalculating statistics for numeric columns:\n");
    df_describe(df);
    
    df_free(df);
    
    return 0;
}