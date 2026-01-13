/*
** EPITECH PROJECT, 2025
** lingo
** File description:
** yes
*/

#include "../include/lingo.h"

char **realloc_list(size_t *capacity, char **words)
{
    char **new_word_list = NULL;

    *capacity *= 2;
    new_word_list = realloc(words, sizeof(char *) * (*capacity));
    return new_word_list;
}
