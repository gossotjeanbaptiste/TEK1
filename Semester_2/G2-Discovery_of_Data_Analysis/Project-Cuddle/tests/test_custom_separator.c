/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Test custom separator in df_read_csv
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

// Create a test CSV file with semicolon separator
void create_test_csv_semicolon(void)
{
    FILE *file = fopen("test_semicolon.csv", "w");
    if (!file)
        return;
    
    fprintf(file, "name;age;score;city\n");
    fprintf(file, "Alice;25;85.5;Paris\n");
    fprintf(file, "Bob;30;92.3;London\n");
    fprintf(file, "Charlie;22;78.9;Berlin\n");
    fprintf(file, "David;35;88.7;Madrid\n");
    fprintf(file, "Eve;28;95.2;Rome\n");
    
    fclose(file);
}

// Create a test CSV file with tab separator
void create_test_csv_tab(void)
{
    FILE *file = fopen("test_tab.csv", "w");
    if (!file)
        return;
    
    fprintf(file, "name\tage\tscore\tcity\n");
    fprintf(file, "Alice\t25\t85.5\tParis\n");
    fprintf(file, "Bob\t30\t92.3\tLondon\n");
    fprintf(file, "Charlie\t22\t78.9\tBerlin\n");
    fprintf(file, "David\t35\t88.7\tMadrid\n");
    fprintf(file, "Eve\t28\t95.2\tRome\n");
    
    fclose(file);
}

int main(void)
{
    // Test with semicolon separator
    printf("=== Testing with semicolon separator ===\n");
    create_test_csv_semicolon();
    
    dataframe_t *df_semicolon = df_read_csv("test_semicolon.csv", ";");
    if (!df_semicolon) {
        printf("Failed to read CSV with semicolon separator\n");
        return 84;
    }
    
    printf("Successfully read CSV with semicolon separator\n");
    printf("Dataframe shape: (%d, %d)\n", df_semicolon->nb_rows, df_semicolon->nb_columns);
    
    df_info(df_semicolon);
    df_describe(df_semicolon);
    
    // Write the dataframe to a new CSV file
    if (df_write_csv(df_semicolon, "output_semicolon.csv") != 0) {
        printf("Failed to write CSV with semicolon separator\n");
        df_free(df_semicolon);
        return 84;
    }
    
    printf("Successfully wrote CSV with semicolon separator\n");
    df_free(df_semicolon);
    
    // Test with tab separator
    printf("\n=== Testing with tab separator ===\n");
    create_test_csv_tab();
    
    dataframe_t *df_tab = df_read_csv("test_tab.csv", "\t");
    if (!df_tab) {
        printf("Failed to read CSV with tab separator\n");
        return 84;
    }
    
    printf("Successfully read CSV with tab separator\n");
    printf("Dataframe shape: (%d, %d)\n", df_tab->nb_rows, df_tab->nb_columns);
    
    df_info(df_tab);
    df_describe(df_tab);
    
    // Write the dataframe to a new CSV file
    if (df_write_csv(df_tab, "output_tab.csv") != 0) {
        printf("Failed to write CSV with tab separator\n");
        df_free(df_tab);
        return 84;
    }
    
    printf("Successfully wrote CSV with tab separator\n");
    df_free(df_tab);
    
    return 0;
}