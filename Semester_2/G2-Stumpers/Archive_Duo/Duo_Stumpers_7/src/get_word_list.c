/*
** EPITECH PROJECT, 2025
** yes
** File description:
** yes
*/

#include "../include/lingo.h"

char **get_word_list(FILE * file, size_t *word_number)
{
    size_t capacity = 2;
    size_t len = 0;
    char *line = NULL;
    char **words = malloc(sizeof(char *) * capacity);

    if (!words)
        return NULL;
    while (getline(&line, &len, file) != -1) {
        if (*word_number + 1 > capacity)
            words = realloc_list(&capacity, words);
        words[*word_number] = strdup(line);
        if (!words[*word_number])
            return NULL;
        (*word_number)++;
    }
    free(line);
    return words;
}
