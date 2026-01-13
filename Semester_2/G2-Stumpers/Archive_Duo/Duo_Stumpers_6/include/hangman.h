/*
** EPITECH PROJECT, 2025
** hangman
** File description:
** header
*/

#ifndef HANGMAN_H
	#define HANGMAN_H
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <ctype.h>

bool verify_word(char const *original, char *word, size_t *tries);
char *read_line(FILE *file, int nb);
char *obfuscate_word(const char *word);
bool my_isspace(const char c);

#endif
