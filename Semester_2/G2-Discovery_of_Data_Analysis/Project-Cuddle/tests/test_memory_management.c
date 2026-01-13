/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Test memory management and double free
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

void create_test_csv(void)
{
    FILE *file = fopen("test_memory.csv", "w");
    if (!file)
        return;
    
    fprintf(file, "name,age,score,active\n");
    fprintf(file, "Alice,25,85.5,true\n");
    fprintf(file, "Bob,30,92.3,true\n");
    fprintf(file, "Charlie,22,78.9,false\n");
    fprintf(file, "David,35,88.7,true\n");
    fprintf(file, "Eve,28,95.2,false\n");
    
    fclose(file);
}

void test_head_tail(dataframe_t *df)
{
    printf("\n=== Testing df_head and df_tail ===\n");
    
    dataframe_t *head_df = df_head(df, 2);
    if (!head_df) {
        printf("Failed to create head dataframe\n");
        return;
    }
    
    printf("Successfully created head dataframe with %d rows\n", head_df->nb_rows);
    
    dataframe_t *tail_df = df_tail(df, 2);
    if (!tail_df) {
        printf("Failed to create tail dataframe\n");
        df_free(head_df);
        return;
    }
    
    printf("Successfully created tail dataframe with %d rows\n", tail_df->nb_rows);
    
    printf("Freeing head dataframe...\n");
    df_free(head_df);
    
    printf("Freeing tail dataframe...\n");
    df_free(tail_df);
    
    printf("Successfully freed head and tail dataframes\n");
}

void test_nested_operations(dataframe_t *df)
{
    printf("\n=== Testing nested operations ===\n");
    
    dataframe_t *head_df = df_head(df, 3);
    if (!head_df) {
        printf("Failed to create head dataframe\n");
        return;
    }

    dataframe_t *tail_of_head = df_tail(head_df, 2);
    if (!tail_of_head) {
        printf("Failed to create tail of head dataframe\n");
        df_free(head_df);
        return;
    }
    
    printf("Successfully created tail of head dataframe with %d rows\n", tail_of_head->nb_rows);

    printf("Freeing tail of head dataframe...\n");
    df_free(tail_of_head);
    
    printf("Freeing head dataframe...\n");
    df_free(head_df);
    
    printf("Successfully freed nested dataframes\n");
}

void test_multiple_operations(dataframe_t *df)
{
    printf("\n=== Testing multiple operations on the same dataframe ===\n");

    dataframe_shape_t shape = df_shape(df);
    printf("Dataframe shape: (%d, %d)\n", shape.nb_rows, shape.nb_columns);

    printf("Dataframe info:\n");
    df_info(df);

    printf("Dataframe describe:\n");
    df_describe(df);
    
    printf("Successfully performed multiple operations on the same dataframe\n");
}


void test_null_free(void)
{
    printf("\n=== Testing NULL dataframe free ===\n");

    df_free(NULL);
    
    printf("Successfully handled NULL dataframe free\n");
}

int main(void)
{
    printf("=== Testing memory management and double free prevention ===\n");
    create_test_csv();
    
    dataframe_t *df = df_read_csv("test_memory.csv", ",");
    if (!df) {
        printf("Failed to read CSV file\n");
        return 84;
    }
    
    printf("Successfully read CSV file\n");
    printf("Dataframe shape: (%d, %d)\n", df->nb_rows, df->nb_columns);

    test_head_tail(df);
    test_nested_operations(df);
    test_multiple_operations(df);
    test_null_free();

    printf("\nFreeing original dataframe...\n");
    df_free(df);
    
    printf("\n=== All memory management tests completed successfully ===\n");
    
    return 0;
}