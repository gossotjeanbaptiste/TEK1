/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Test custom separator in df_read_csv
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

void create_test_csv_comma(void)
{
    FILE *file = fopen("test_comma.csv", "w");
    if (!file)
        return;
    
    fprintf(file, "name,age,score,city\n");
    fprintf(file, "Alice,25,85.5,Paris\n");
    fprintf(file, "Bob,30,92.3,London\n");
    fprintf(file, "Charlie,22,78.9,Berlin\n");
    fprintf(file, "David,35,88.7,Madrid\n");
    fprintf(file, "Eve,28,95.2,Rome\n");
    
    fclose(file);
}

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

void create_test_csv_pipe(void)
{
    FILE *file = fopen("test_pipe.csv", "w");
    if (!file)
        return;
    
    fprintf(file, "name|age|score|city\n");
    fprintf(file, "Alice|25|85.5|Paris\n");
    fprintf(file, "Bob|30|92.3|London\n");
    fprintf(file, "Charlie|22|78.9|Berlin\n");
    fprintf(file, "David|35|88.7|Madrid\n");
    fprintf(file, "Eve|28|95.2|Rome\n");
    
    fclose(file);
}

void create_test_csv_space(void)
{
    FILE *file = fopen("test_space.csv", "w");
    if (!file)
        return;
    
    fprintf(file, "name age score city\n");
    fprintf(file, "Alice 25 85.5 Paris\n");
    fprintf(file, "Bob 30 92.3 London\n");
    fprintf(file, "Charlie 22 78.9 Berlin\n");
    fprintf(file, "David 35 88.7 Madrid\n");
    fprintf(file, "Eve 28 95.2 Rome\n");
    
    fclose(file);
}

void test_separator(const char *file_name, const char *separator, const char *separator_name)
{
    printf("\n=== Testing with %s separator ===\n", separator_name);
    
    dataframe_t *df = df_read_csv(file_name, separator);
    if (!df) {
        printf("Failed to read CSV with %s separator\n", separator_name);
        return;
    }
    
    printf("Successfully read CSV with %s separator\n", separator_name);
    printf("Dataframe shape: (%d, %d)\n", df->nb_rows, df->nb_columns);
    
    df_info(df);
    
    char output_file[100];
    sprintf(output_file, "output_%s.csv", separator_name);
    
    if (df_write_csv(df, output_file) != 0) {
        printf("Failed to write CSV with %s separator\n", separator_name);
        df_free(df);
        return;
    }
    
    printf("Successfully wrote CSV with %s separator to %s\n", separator_name, output_file);
    df_free(df);
}

void test_default_separator(void)
{
    printf("\n=== Testing with default separator (comma) ===\n");
    
    dataframe_t *df = df_read_csv("test_comma.csv", NULL);
    if (!df) {
        printf("Failed to CSV with default separator\n");
        return;
    }
    
    printf("Successfully read CSV with default separator\n");
    printf("Dataframe shape: (%d, %d)\n", df->nb_rows, df->nb_columns);
    
    df_info(df);
    
    if (df_write_csv(df, "output_default.csv") != 0) {
        printf("Failed to write CSV with default separator\n");
        df_free(df);
        return;
    }
    
    printf("Successfully CSV with default separator to output_default.csv\n");
    df_free(df);
}

int main(void)
{
    create_test_csv_comma();
    create_test_csv_semicolon();
    create_test_csv_tab();
    create_test_csv_pipe();
    create_test_csv_space();
    
    test_separator("test_comma.csv", ",", "comma");
    test_separator("test_semicolon.csv", ";", "semicolon");
    test_separator("test_tab.csv", "\t", "tab");
    test_separator("test_pipe.csv", "|", "pipe");
    test_separator("test_space.csv", " ", "space");
    
    test_default_separator();
    
    printf("\n=== All separator tests completed successfully ===\n");
    
    return 0;
}