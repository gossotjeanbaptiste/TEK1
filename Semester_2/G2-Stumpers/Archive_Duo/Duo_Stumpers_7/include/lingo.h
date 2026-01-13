/*
** EPITECH PROJECT, 2025
** lingo
** File description:
** lingo
*/

#ifndef LINGO_H_
    #define LINGO_H_
    #define RETURN_ERROR 84
    #define RETURN_SUCCESS 0
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
char **realloc_list(size_t *capacity, char **words);
int read_guess(char **guess);
bool validate_guess(const char *guess,
    char *obfuscated_word, const char *random_word, size_t round_count);
bool play_round(const char *random_word, char *obfuscated_word,
    char **guess, size_t round_count);
char *get_random_word(FILE *file);
void free_word_list(char **words, const size_t *word_count);
char **get_word_list(FILE * file, size_t *word_number);
#endif
