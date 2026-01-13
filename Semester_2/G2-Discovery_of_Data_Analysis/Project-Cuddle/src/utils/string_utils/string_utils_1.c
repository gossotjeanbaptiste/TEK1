/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** String utility functions for the Cuddle library
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/utils.h"
#include "../../../include/dataframe.h"

bool is_numeric(const char *str)
{
    int i;

    if (!str || !str[0])
        return false;
    i = 0;
    if (str[0] == '-')
        i++;
    for (; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool is_float(const char *str)
{
    int i;

    if (!str || !str[0])
        return false;
    i = 0;
    if (str[0] == '-')
        i++;
    for (; str[i]; i++) {
        if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
            return false;
    }
    return true;
}

bool is_bool(const char *str)
{
    if (!str)
        return false;
    return (strcasecmp(str, "true") == 0 || strcasecmp(str, "false") == 0);
}

static int count_tokens_helper(char *str_copy, const char *sep_copy)
{
    int count = 0;
    char *token = strtok(str_copy, sep_copy);

    while (token != NULL) {
        count++;
        token = strtok(NULL, sep_copy);
    }
    return count;
}

int count_tokens(const char *line, const char *separator)
{
    int count = 0;
    char *tmp;
    char *sep_copy;

    if (!line || !separator)
        return 0;
    tmp = strdup(line);
    sep_copy = strdup(separator);
    if (!tmp || !sep_copy) {
        free(tmp);
        free(sep_copy);
        return 0;
    }
    count = count_tokens_helper(tmp, sep_copy);
    free(tmp);
    free(sep_copy);
    return count;
}
