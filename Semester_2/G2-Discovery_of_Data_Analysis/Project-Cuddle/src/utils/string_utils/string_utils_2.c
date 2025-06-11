/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** String utility functions for the Cuddle library (part 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

static char **allocate_tokens(int count, const char *line)
{
    char **tokens;
    int i;

    (void)line;
    tokens = malloc(sizeof(char *) * (count + 1));
    if (!tokens)
        return NULL;
    for (i = 0; i <= count; i++)
        tokens[i] = NULL;
    return tokens;
}

static void fill_tokens(char **tokens, char *tmp, const char *separator)
{
    char *token;
    int i;
    char *sep_copy;

    sep_copy = strdup(separator);
    if (!sep_copy)
        return;
    token = strtok(tmp, sep_copy);
    i = 0;
    while (token != NULL) {
        tokens[i] = strdup(token);
        token = strtok(NULL, sep_copy);
        i++;
    }
    free(sep_copy);
}

char **split_line(const char *line, const char *separator)
{
    int count;
    char **tokens;
    char *tmp;

    if (!line || !separator)
        return NULL;
    count = count_tokens(line, separator);
    if (count == 0)
        return NULL;
    tokens = allocate_tokens(count, line);
    tmp = strdup(line);
    if (!tokens || !tmp) {
        free(tmp);
        free_tokens(tokens);
        return NULL;
    }
    fill_tokens(tokens, tmp, separator);
    free(tmp);
    return tokens;
}

const char *get_type_name(column_type_t type)
{
    switch (type) {
    case BOOL:
        return "bool";
    case INT:
        return "int";
    case UINT:
        return "unsigned int";
    case FLOAT:
        return "float";
    case STRING:
        return "string";
    default:
        return "unknown";
    }
}
