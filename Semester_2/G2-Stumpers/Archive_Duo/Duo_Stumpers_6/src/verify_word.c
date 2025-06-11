/*
** EPITECH PROJECT, 2025
** hangman
** File description:
** verify_word
*/
#include "../include/hangman.h"

static bool make_try(const char *original, char *word, const char character)
{
    bool has_changed = false;

    for (int i = 0; word[i]; i++) {
        if (original[i] == character) {
            word[i] = character;
            has_changed = true;
        }
    }
    return has_changed;
}

static bool verif(char *word, const char *original, const char *line, size_t *tries)
{
    if (strlen(line) != 1) {
        fprintf(stderr, "A letter only!\n");
        return false;
        }
    if (!make_try(original, word, line[0])) {
        printf("%c: is not in this word\n", line[0]);
        (*tries)--;
        return false;
    }
    return false;
}

bool verify_word(char const *original, char *word, size_t *tries)
{
    char *line = NULL;
    size_t len = 0;

    printf("%s\n", word);
    printf("Tries: %zu\n\nYour letter: ", *tries);
    if (getline(&line, &len, stdin) != -1) {
        line[strlen(line) - 1] = '\0';
        return verif(word, original, line, tries);
    }
    free(line);
    return false;
}
