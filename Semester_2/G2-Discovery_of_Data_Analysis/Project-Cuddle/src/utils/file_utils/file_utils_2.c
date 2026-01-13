/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** File utility functions for the Cuddle library (part 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

int count_lines(FILE *file)
{
    int count = 0;
    int ch;
    bool has_chars = false;

    ch = fgetc(file);
    while (ch != EOF) {
        if (ch == '\n') {
            count++;
            has_chars = false;
        } else {
            has_chars = true;
        }
        ch = fgetc(file);
    }
    if (has_chars)
        count++;
    rewind(file);
    return count;
}

void handle_error(const char *message, FILE *file,
    __attribute__((unused)) char *sep)
{
    fprintf(stderr, "Error: %s\n", message);
    if (file)
        fclose(file);
}

void write_bool_value(FILE *file, void *value)
{
    if (!value)
        return;
    fprintf(file, "%s", *(bool *)value ? "true" : "false");
}

void write_int_value(FILE *file, void *value)
{
    if (!value)
        return;
    fprintf(file, "%d", *(int *)value);
}

void write_uint_value(FILE *file, void *value)
{
    if (!value)
        return;
    fprintf(file, "%u", *(unsigned int *)value);
}
