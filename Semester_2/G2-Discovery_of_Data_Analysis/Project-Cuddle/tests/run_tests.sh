#!/bin/bash

cd "/media/justwireless/Shared/Epitech-Shared/Epitech-G1-(Semester-2)/G2-Discovery_of_Data_Analysis/Project-Cuddle/tests"

make

mkdir -p tests/output

echo "name,age,city
Alice,25,Paris
Bob,30,London
Charlie,35,Berlin
Léo,25,Paris
Nathan,30,London
Alex,35,Berlin
Paul,25,Paris" > tests/data.csv

echo "string,int,uint,float,bool
test,-10,10,10.5,true
example,-5,20,15.0,false
sample,0,30,25.0,true" > types.csv

echo "amount,num
25.0e,10
30.0e,20
35.0e,30" > tests/money.csv

# Test 1: df_read_csv and df_write_csv
echo -e "\n=== Test 1: df_read_csv and df_write_csv ==="
cat > test_main.c << EOF
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
    
    int result = df_write_csv(dataframe, "tests/output/data.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        return 84;
    }
    
    printf("Successfully read and wrote CSV file\n");
    df_free(dataframe);
    return 0;
}
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main
cat tests/output/data.csv

# Test 2: df_head
echo -e "\n=== Test 2: df_head ==="
cat > test_main.c << EOF
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
    
    int result = df_write_csv(head, "tests/output/head.csv");
    
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
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main
cat tests/output/head.csv

# Test 3: df_tail
echo -e "\n=== Test 3: df_tail ==="
cat > test_main.c << EOF
#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/tests/data.csv");
    
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
    
    int result = df_write_csv(tail, "tests/output/tail.csv");
    
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
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main
cat tests/output/tail.csv

# Test 4: df_shape
echo -e "\n=== Test 4: df_shape ==="
cat > test_main.c << EOF
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
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main

# Test 5: df_info
echo -e "\n=== Test 5: df_info ==="
cat > test_main.c << EOF
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
    
    // Test with different types
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
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main

# Test 6: df_describe
echo -e "\n=== Test 6: df_describe ==="
cat > test_main.c << EOF
#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv");
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    printf("Dataframe description:\n");
    df_describe(dataframe);
    
    df_free(dataframe);
    
    // Test with different types
    dataframe_t *types_df = df_read_csv("tests/types.csv", NULL);
    
    if (!types_df) {
        fprintf(stderr, "Failed to read types CSV file\n");
        return 84;
    }
    
    printf("\nTypes dataframe description:\n");
    df_describe(types_df);
    
    df_free(types_df);
    return 0;
}
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main

# Test 7: df_filter
echo -e "\n=== Test 7: df_filter ==="
cat > test_main.c << EOF
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dataframe.h"

bool filter_func(void *value)
{
    return *(int *)value > 30;
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv", NULL);
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    dataframe_t *filtered = df_filter(dataframe, "age", filter_func);
    
    if (!filtered) {
        fprintf(stderr, "Failed to filter dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(filtered, "tests/output/filtered.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(filtered);
        return 84;
    }
    
    printf("Successfully filtered dataframe\n");
    df_free(dataframe);
    df_free(filtered);
    return 0;
}
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main
cat tests/output/filtered.csv

# Test 8: df_sort
echo -e "\n=== Test 8: df_sort ==="
cat > test_main.c << EOF
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dataframe.h"

bool sort_func(void *value1, void *value2)
{
    return *(int *)value1 > *(int *)value2;
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv", NULL);
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    dataframe_t *sorted = df_sort(dataframe, "age", sort_func);
    
    if (!sorted) {
        fprintf(stderr, "Failed to sort dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(sorted, "tests/output/sorted.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(sorted);
        return 84;
    }
    
    printf("Successfully sorted dataframe\n");
    df_free(dataframe);
    df_free(sorted);
    return 0;
}
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main
cat tests/output/sorted.csv

# Test 9: df_groupby
echo -e "\n=== Test 9: df_groupby ==="
cat > test_main.c << EOF
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

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv", NULL);
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    dataframe_t *grouped = df_groupby(dataframe, "city", (const char *[]){"age"}, agg_func);
    
    if (!grouped) {
        fprintf(stderr, "Failed to group dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(grouped, "tests/output/grouped.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(grouped);
        return 84;
    }
    
    printf("Successfully grouped dataframe\n");
    df_free(dataframe);
    df_free(grouped);
    return 0;
}
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main
cat tests/output/grouped.csv

# Test 10: df_apply
echo -e "\n=== Test 10: df_apply ==="
cat > test_main.c << EOF
#include <stdio.h>
#include <stdlib.h>
#include "../include/dataframe.h"

void *apply_func(void *value)
{
    int *new_value = malloc(sizeof(int));
    *new_value = *(int *)value * 2;
    return new_value;
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("tests/data.csv", NULL);
    
    if (!dataframe) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 84;
    }
    
    dataframe_t *applied = df_apply(dataframe, "age", apply_func);
    
    if (!applied) {
        fprintf(stderr, "Failed to apply function to dataframe\n");
        df_free(dataframe);
        return 84;
    }
    
    int result = df_write_csv(applied, "tests/output/applied.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(dataframe);
        df_free(applied);
        return 84;
    }
    
    printf("Successfully applied function to dataframe\n");
    df_free(dataframe);
    df_free(applied);
    return 0;
}
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main
cat tests/output/applied.csv

# Test 11: // ERROR // df_to_type with string to float conversion // ERROR //
echo -e "\n=== Test 11: df_to_type with string to float conversion ==="
cat > test_main.c << EOF
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
    
    int result = df_write_csv(applied_money, "tests/output/applied_money.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(money_df);
        df_free(applied_money);
        return 84;
    }
    
    dataframe_t *converted_money = df_to_type(applied_money, "amount", FLOAT);
    
    if (!converted_money) {
        fprintf(stderr, "Failed to convert money dataframe to float\n");
        df_free(money_df);
        df_free(applied_money);
        return 84;
    }
    
    printf("\nConverted money dataframe info:\n");
    df_info(converted_money);
    
    result = df_write_csv(converted_money, "tests/output/converted_money.csv");
    
    if (result != 0) {
        fprintf(stderr, "Failed to write CSV file\n");
        df_free(money_df);
        df_free(applied_money);
        df_free(converted_money);
        return 84;
    }
    
    printf("Successfully converted money dataframe to float\n");
    
    df_free(money_df);
    df_free(applied_money);
    df_free(converted_money);
    return 0;
}
EOF

gcc -Wall -Wextra -o test_main test_main.c -L. -lcuddle -lm
./test_main
cat tests/output/converted_money.csv

# Clean
rm -f test_main

echo -e "\nAll tests completed!"