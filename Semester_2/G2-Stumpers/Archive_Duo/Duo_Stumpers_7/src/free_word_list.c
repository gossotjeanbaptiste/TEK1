/*
** EPITECH PROJECT, 2025
** yes
** File description:
** yes
*/

#include "../include/lingo.h"

void free_word_list(char **words, const size_t *word_count)
{
    for (size_t i = 0; i < *word_count; i++)
        free(words[i]);
    free(words);
}
