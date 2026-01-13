#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataframe.h"

void *apply_func(void *value)
{
    char *str = (char *)value;
    char *new_str = strdup(str);
    
    if (new_str && strlen(new_str) > 0 && new_str[strlen(new_str) - 1] == 'e') {
        new_str[strlen(new_str) - 1] = '\0';
    }
    
    return new_str;
}

int main(void)
{
    dataframe_t *money_df = df_read_csv("tests/money.csv", NULL);
    
    if (!money_df) {
        fprintf(stderr, "Failed to read money CSV file\n");
        return 84;
    }
    
    printf("Original money dataframe info:\n");
    df_info(money_df);
    
    dataframe_t *applied_money = df_apply(money_df, "amount", apply_func);
    
    if (!applied_money) {
        fprintf(stderr, "Failed to apply function to money dataframe\n");
        df_free(money_df);
        return 84;
    }
    
    printf("\nApplied money dataframe info:\n");
    df_info(applied_money);
    
    dataframe_t *converted_money = df_to_type(applied_money, "amount", FLOAT);
    
    if (!converted_money) {
        fprintf(stderr, "Failed to convert money dataframe to float\n");
        df_free(money_df);
        df_free(applied_money);
        return 84;
    }
    
    printf("\nConverted money dataframe info:\n");
    df_info(converted_money);
    
    int result = df_write_csv(converted_money, "converted_money.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(money_df);
        df_free(applied_money);
        df_free(converted_money);
        return 84;
    }
    
    printf("Successfully converted money dataframe to float\n");
    
    dataframe_t *types_df = df_read_csv("tests/types.csv", NULL);
    
    if (!types_df) {
        fprintf(stderr, "Failed to read types CSV file\n");
        df_free(money_df);
        df_free(applied_money);
        df_free(converted_money);
        return 84;
    }
    
    printf("\nOriginal types dataframe info:\n");
    df_info(types_df);
    
    dataframe_t *converted_types = df_to_type(types_df, "float", INT);
    
    if (!converted_types) {
        fprintf(stderr, "Failed to convert types dataframe float to int\n");
        df_free(money_df);
        df_free(applied_money);
        df_free(converted_money);
        df_free(types_df);
        return 84;
    }
    
    printf("\nConverted types dataframe info:\n");
    df_info(converted_types);
    
    result = df_write_csv(converted_types, "converted_types.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(money_df);
        df_free(applied_money);
        df_free(converted_money);
        df_free(types_df);
        df_free(converted_types);
        return 84;
    }
    
    printf("Successfully converted types dataframe float to int\n");
    
    df_free(money_df);
    df_free(applied_money);
    df_free(converted_money);
    df_free(types_df);
    df_free(converted_types);
    return 0;
}