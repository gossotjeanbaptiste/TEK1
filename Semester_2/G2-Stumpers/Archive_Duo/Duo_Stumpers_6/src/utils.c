/*
** EPITECH PROJECT, 2025
** hangman
** File description:
** main
*/

#include "../include/hangman.h"

char *read_line(FILE *file, int nb)
{
    char *line = NULL;
    size_t len = 0;

    for (int i = 0; i < nb; i++)
        if (getline(&line, &len, file) == -1)
            return NULL;
    return line;
}

char *obfuscate_word(const char *word)
{
    char *obfuscated_word = NULL;

    if (!word)
        return NULL;
    obfuscated_word = strdup(word);
    for (int i = 0 ; word[i] != '\n' && word[i] != '\0'; i++)
        obfuscated_word[i] = '*';
    return obfuscated_word;
}

bool my_isspace(const char c)
{
    return (c == ' ' || c == '\t' || c == '\f'
        || c == '\v' || c == '\r' );
}
