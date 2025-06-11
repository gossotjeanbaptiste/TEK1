/*
** EPITECH PROJECT, 2025
** yes
** File description:
** yes
*/

#include "../include/lingo.h"

char *get_random_word(FILE *file)
{
    size_t word_number = 0;
    char **words = get_word_list(file, &word_number);
    char *random_word = NULL;

    if (!words)
        return NULL;
    random_word = strdup(words[rand() % word_number]);
    random_word[strlen(random_word) - 1] = '\0';
    free_word_list(words, &word_number);
    if (!random_word)
        return NULL;
    return random_word;
}
